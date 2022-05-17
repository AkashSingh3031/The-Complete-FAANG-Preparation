from PyQt5.QtWidgets import QApplication, QMainWindow, QWidget, QPushButton, QVBoxLayout, QFileDialog , QMessageBox
from PyQt5.uic.properties import QtCore
from PyQt5.QtCore import pyqtSignal
from PyQt5 import QtWidgets, uic
import mplwidget

import matplotlib.pyplot as plt
from scipy import signal
import pandas as pd 
import numpy as np
import sys
import os

from mpl_toolkits.axes_grid1.axes_divider import make_axes_locatable
import more_itertools as mit 
from sklearn.metrics import mean_absolute_error
from sympy import S, symbols, printing

import logging
import time 

logging.basicConfig(format='%(asctime)s %(levelname)-8s [%(filename)s:%(lineno)d] %(message)s',datefmt='%d-%m-%Y:%H:%M:%S',
level=logging.INFO,filename='Interpolation.txt')

class MainWindow(QtWidgets.QMainWindow):
    def __init__(self):   
        super(MainWindow, self).__init__()
        uic.loadUi('Gui.ui', self)
        self.setWindowTitle("Interpolation application")
        self.actionOpen.triggered.connect(self.open)
        
        self.display.clicked.connect(self.chunk)
        self.degree_slider.valueChanged.connect(self.chunk)
        self.dataPer_slider.valueChanged.connect(self.chunk)
        self.chunk_box.valueChanged.connect(self.chunk)
        self.overlap_box.valueChanged.connect(self.chunk)
        
        self.errorMap.clicked.connect(self.error_map)
        
        self.equation_comboBox.currentIndexChanged.connect(self.changeTitle)
        self.MplWidget.canvas.axes.set_facecolor('black')
        self.MplWidget2.canvas.axes.set_facecolor('black')
        self.show()
        
    def open(self):
        global data0
        try:
            path = QFileDialog.getOpenFileName(self, 'Open a file', '', 'Choose arbitrary signal(*.csv)')
        except wave.Error:
            logging.error("The user didn't open a .csv file")
        if path != ('', ''):
            data0 = path[0]     
            logging.info("The user open an signal file path: " + data0)
            
    def thread(self):
        t1=Thread(target=self.Operation)
        t1.start()
        
    def chunk(self):
        global data0        
        global chunks,degree,x,y,modelInterpolation,x_chunks,y_chunks ,overlap    
        
        data = pd.read_csv(data0)
        x_data = data[data.columns[0]].to_numpy()
        y_data = data[data.columns[1]].to_numpy()
        chunks = int(self.chunk_box.value())
        logging.info("The user choose the number of chunks as : " + str(chunks))
        degree = self.degree_slider.value()
        logging.info("The user choose the number of degree as : " + str(degree))
        
        if(chunks==1):
            logging.info("The user has chosen extrapolation model ")
            self.equation_comboBox.clear()
            self.dataPer_slider.setEnabled(True)
            change = round(self.dataPer_slider.value() / 100 * len(x_data)) # changing %
            x = x_data[:change]  # change from last value towards beginning of array
            y = y_data[:change]  # change from last value towards beginning of array
            
            modelExtrapolation = np.poly1d(np.polyfit(x, y, degree))
            self.MplWidget.canvas.axes.clear()
            self.MplWidget.canvas.axes.plot(x_data, y_data, '--')
            
            y_extrpolation = modelExtrapolation(x_data)
            print(y_extrpolation)
            
            self.MplWidget.canvas.axes.plot(x_data, y_extrpolation, '-.')
            logging.debug("modelExtrapolation has been done successfuly plotted ")

            p = np.polyfit(x, y, degree) 
            xSymbols = symbols("x")
            poly = sum(S("{:6.2f}".format(v))*xSymbols**i for i, v in enumerate(p[::1]))
            eq_latex = printing.latex(poly)
            label="${}$".format(eq_latex)
            logging.debug("LateX has been done successfuly ")

            #print(label)
            self.MplWidget.canvas.axes.set_title(label, color='r', fontsize=15)
            self.MplWidget.canvas.draw()
            
        else:
            logging.info("The user has chosen interpolation model ")

            self.dataPer_slider.setValue(100)
            self.dataPer_slider.setEnabled(False)
            change = round(100 / 100 * len(x_data)) # changing %    
            x = x_data[:change]  # change from last value towards beginning of array
            y = y_data[:change]  # change from last value towards beginning of array
   
            n=int((len(x)-1)/chunks)
            overlap=int(self.overlap_box.value())
            #overlap=0
            logging.info("The user has chosen overlapping percentage :" +str(overlap) )

            if(overlap>=0 and overlap<=25):
                k=int((overlap/100)*((len(x)-1)/chunks))
                x_chunks = list(mit.windowed(x, n=int(len(x)/chunks), step=n-k))
                y_chunks = list(mit.windowed(y, n=int(len(x)/chunks), step=n-k))
                self.MplWidget.canvas.axes.clear()

            self.MplWidget.canvas.axes.plot(x_data, y_data,'--')
            #labels = []
            self.equation_comboBox.clear()
            
            for i in range(chunks):
                self.MplWidget.canvas.axes.tick_params(axis="x", colors="white")
                self.MplWidget.canvas.axes.tick_params(axis="y", colors="white")
                #self.MplWidget.canvas.axes.plot(x_chunks[i], y_chunks[i],'--') 
                
                modelInterpolation = np.poly1d(np.polyfit(x_chunks[i], y_chunks[i], degree))
                self.MplWidget.canvas.axes.plot(x_chunks[i], modelInterpolation(x_chunks[i]), '-.')
                logging.info("modelInterpolation has been done successfuly plotted ")

                p = np.polyfit(x_chunks[i], y_chunks[i], degree)  
                xSymbols = symbols("x")
                poly = sum(S("{:6.2f}".format(v))*xSymbols**i for i, v in enumerate(p[::1]))
                eq_latex = printing.latex(poly)
                
                label="${}$".format(eq_latex)
                logging.debug("LateX has been done succefuly ")

                self.equation_comboBox.addItem(label)
                
                self.MplWidget.canvas.draw()
                
        self.MplWidget.canvas.draw()
    
    def changeTitle(self):
        self.MplWidget.canvas.axes.set_title(self.equation_comboBox.currentText() , color='r', fontsize=15)
        self.MplWidget.canvas.draw()
        
######################################### Error Map ##################################
    def error_map(self):
        global chunks,degree,x,y,modelInterpolation,x_chunks,y_chunks,overlap
        self.errorMap.setText("stop")
        valueX = eval(self.X_axis_box.currentText())
        valueY = eval(self.Y_axis_box.currentText())
        
        if(self.X_axis_box.currentText() == self.Y_axis_box.currentText()) :
            logging.warning('The user chose ' + self.Y_axis_box.currentText() + 'for the 2 axis ') 
                
        x_range =range(1,valueX+1 ) 
        y_range =range(1, valueY+1 ) 
      
        modelInterpolation = np.poly1d(np.polyfit(x, y, degree))
        Overall_Error = mean_absolute_error(y, modelInterpolation(x))*100
        rounded_Error= round(Overall_Error,2)
        errors=[]
        for i in range(1,degree+1):
            degrees = np.poly1d(np.polyfit(x, y, i))
            for j in range(chunks):
                errors.append(mean_absolute_error(y_chunks[j],degrees(x_chunks[j])))

        errors_2d = np.reshape(errors, (valueY, valueX))
        logging.debug("Errors has been generated sucessfully")

        self.MplWidget2.canvas.axes.clear()        
        self.MplWidget2.canvas.axes.tick_params(axis="x", colors="white")
        self.MplWidget2.canvas.axes.tick_params(axis="y", colors="white")        
        self.MplWidget2.canvas.axes.set_title("Percentage Error = " + str(rounded_Error) + ' %', color='r', fontsize=15)
        
        cax = make_axes_locatable(self.MplWidget2.canvas.axes).append_axes("right", size="5%", pad="2%")
        cax.tick_params(axis="x", colors="white")
        cax.tick_params(axis="y", colors="white")
         
        cf = self.MplWidget2.canvas.axes.contourf(x_range,y_range,errors_2d)
        self.MplWidget2.canvas.axes.figure.colorbar(cf , cax=cax)   
        
        for i in range(100):
            time.sleep(0.00001)
            self.progressBar.setValue(i+1)
        
        self.MplWidget2.canvas.draw()    
        QMessageBox.information(self , "Error Map Completed" , "The Error Map has been generated Successfully ")
        self.errorMap.setText("start")
        self.progressBar.setValue(0)
        cax.remove()
        
app = 0
app = QtWidgets.QApplication(sys.argv)
window = MainWindow()
app.exec_()        