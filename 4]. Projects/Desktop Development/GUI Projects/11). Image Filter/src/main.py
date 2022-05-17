from PyQt5 import QtWidgets, uic
from PyQt5.QtWidgets import *
from PyQt5.QtGui import QPixmap
import numpy as np
import sys
import os
from os import path
import cv2
import matplotlib.pyplot as plt 
from PIL import Image
import skimage.io

# create our own histogram function
def get_histogram(image, bins):
    # array with size of bins, set to zeros
    histogram = np.zeros(bins)
    # loop through pixels and sum up counts of pixels
    for pixel in image:
        histogram[pixel] += 1
    # return our final result
    return histogram

# create our cumulative sum function
def cumsum(a):
    a = iter(a)
    b = [next(a)]
    for i in a:
        b.append(b[-1] + i)
    return np.array(b)


def get_histogram_rgb(image, bins):
    # array with size of bins, set to zeros
    b = image[:,:,0].flatten()
    g = image[:,:,1].flatten()
    r = image[:,:,2].flatten()
    
    histogram_r = np.zeros(bins)
    histogram_g = np.zeros(bins)
    histogram_b = np.zeros(bins)
    
    # loop through pixels and sum up counts of pixels
    for i in r:
        histogram_r[i] += 1
        
    for i in g:
        histogram_g[i] += 1  
    
    for i in b:
        histogram_b[i] += 1
        
    # return our final result
    return (histogram_r,histogram_g,histogram_b)


# function for color image equalization
def histogram_equalization_rgb(img_in):
    # segregate color streams
    b, g, r = cv2.split(img_in)
    h_b, bin_b = np.histogram(b.flatten(), 256, [0, 256])
    h_g, bin_g = np.histogram(g.flatten(), 256, [0, 256])
    h_r, bin_r = np.histogram(r.flatten(), 256, [0, 256])
    # calculate cdf
    cdf_b = np.cumsum(h_b)
    cdf_g = np.cumsum(h_g)
    cdf_r = np.cumsum(h_r)

    # mask all pixels with value=0 and replace it with mean of the pixel values
    cdf_m_b = np.ma.masked_equal(cdf_b, 0)
    cdf_m_b = (cdf_m_b - cdf_m_b.min()) * 255 / (cdf_m_b.max() - cdf_m_b.min())
    cdf_final_b = np.ma.filled(cdf_m_b, 0).astype('uint8')

    cdf_m_g = np.ma.masked_equal(cdf_g, 0)
    cdf_m_g = (cdf_m_g - cdf_m_g.min()) * 255 / (cdf_m_g.max() - cdf_m_g.min())
    cdf_final_g = np.ma.filled(cdf_m_g, 0).astype('uint8')


    cdf_m_r = np.ma.masked_equal(cdf_r, 0)
    cdf_m_r = (cdf_m_r - cdf_m_r.min()) * 255 / (cdf_m_r.max() - cdf_m_r.min())
    cdf_final_r = np.ma.filled(cdf_m_r, 0).astype('uint8')
    # merge the images in the three channels
    img_b = cdf_final_b[b]
    img_g = cdf_final_g[g]
    img_r = cdf_final_r[r]

    img_out = cv2.merge((img_b, img_g, img_r))
    # validation
    equ_b = cv2.equalizeHist(b)
    equ_g = cv2.equalizeHist(g)
    equ_r = cv2.equalizeHist(r)
    equ = cv2.merge((equ_b, equ_g, equ_r))
    # print(equ)

    plt.figure(figsize=(20,20))
    plt.imshow(equ)
    plt.axis('off')
    plt.savefig('./Output images/output.jpg', bbox_inches='tight',pad_inches = 0)
    return img_out


class MainWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        uic.loadUi('filter.ui', self)
        self.actionadd_image.triggered.connect(self.openFileNameDialog) 
        self.btn1.clicked.connect(self.filter)
        self.pushButton.clicked.connect(self.histogram)
        if path.exists("Output images") == False:
            os.mkdir("./Output images")
        
        self.show()
        
    def openFileNameDialog(self):
        path = QFileDialog.getOpenFileName(self, 'Open a file', '', 'Image(*.jpg *.png)')
        if path != ('', ''):
            self.path = path[0]
            self.name = os.path.basename(self.path)
        pixmap = QPixmap(self.path)
        self.filter_input.setPixmap(pixmap)
        self.filter_input.setScaledContents(True)  
        self.input_equalize.setPixmap(pixmap)
        self.input_equalize.setScaledContents(True)  
        
        print(self.path)    
        print(self.name)
        
        self.filter_filtered.clear()
        self.output_equalize.clear()
        self.input_histogram.clear()
        self.output_histogram.clear()
        

    def filter(self):
        img = cv2.imread(self.path)
        
        if self.median.isChecked():
            rgb_img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
            median = cv2.medianBlur(rgb_img,9)

            im = Image.fromarray(median)
            im.save("./Output images/median_filtered.jpg")
            pixmap = QPixmap("./Output images/median_filtered.jpg")
            self.filter_filtered.setPixmap(pixmap)
            self.filter_filtered.setScaledContents(True) 
########################################################################################################            
        elif self.laplacian.isChecked():
            ddepth = cv2.CV_16S
            kernel_size = 9

            imageName = self.path
            imgz = cv2.imread(cv2.samples.findFile(imageName), cv2.IMREAD_COLOR) # Load an image

            smoothed_img = cv2.GaussianBlur(imgz, (3, 3), 0)
            RGB_img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

            gray_img = cv2.cvtColor(smoothed_img, cv2.COLOR_BGR2GRAY)
            laplaced_img = cv2.Laplacian(gray_img, ddepth, ksize=kernel_size)

#             fig = plt.figure(figsize=(12, 12))
#             ax1 = fig.add_subplot(2,2,1)
#             ax1.imshow(laplaced_img, cmap='gray')
            
            plt.imshow(laplaced_img, cmap='gray')
            plt.axis('off')


            plt.savefig('./Output images/laplacian_filtered.jpg', bbox_inches='tight',pad_inches = 0)
            pixmap = QPixmap("./Output images/laplacian_filtered.jpg")
            self.filter_filtered.setPixmap(pixmap)
            self.filter_filtered.setScaledContents(True)
            plt.clf()
###################################################################################
        elif self.lowpass.isChecked():
            # do dft saving as complex output
            dft = np.fft.fft2(img, axes=(0,1))

            # apply shift of origin to center of image
            dft_shift = np.fft.fftshift(dft)

            # generate spectrum from magnitude image (for viewing only)
            mag = np.abs(dft_shift)
            spec = np.log(mag) / 20

            # create circle mask
            radius = 32
            mask = np.zeros_like(img)
            cy = mask.shape[0] // 2
            cx = mask.shape[1] // 2
            cv2.circle(mask, (cx,cy), radius, (255,255,255), -1)[0]

            # blur the mask
            mask2 = cv2.GaussianBlur(mask, (19,19), 0)

            # apply mask to dft_shift
            dft_shift_masked = np.multiply(dft_shift,mask) / 255
            dft_shift_masked2 = np.multiply(dft_shift,mask2) / 255


            # shift origin from center to upper left corner
            back_ishift = np.fft.ifftshift(dft_shift)
            back_ishift_masked = np.fft.ifftshift(dft_shift_masked)
            back_ishift_masked2 = np.fft.ifftshift(dft_shift_masked2)


            # do idft saving as complex output
            img_back = np.fft.ifft2(back_ishift, axes=(0,1))
            img_filtered = np.fft.ifft2(back_ishift_masked, axes=(0,1))
            img_filtered2 = np.fft.ifft2(back_ishift_masked2, axes=(0,1))

            # combine complex real and imaginary components to form (the magnitude for) the original image again
            img_back = np.abs(img_back).clip(0,255).astype(np.uint8)
            img_filtered = np.abs(img_filtered).clip(0,255).astype(np.uint8)
            img_filtered2 = np.abs(img_filtered2).clip(0,255).astype(np.uint8)

            # write result to disk
            cv2.imwrite("./Output images/Lowpass_filtered.jpg", img_filtered2)
            pixmap = QPixmap("./Output images/Lowpass_filtered.jpg")
            self.filter_filtered.setPixmap(pixmap)
            self.filter_filtered.setScaledContents(True)
######################################################################################################            
        elif self.highpass.isChecked():
            # do dft saving as complex output
            dft = np.fft.fft2(img, axes=(0,1))

            # apply shift of origin to center of image
            dft_shift = np.fft.fftshift(dft)

            # generate spectrum from magnitude image (for viewing only)
            mag = np.abs(dft_shift)
            spec = np.log(mag) / 20

            # create white circle mask on black background and invert so black circle on white background
            # as highpass filter
            radius = 32
            mask = np.zeros_like(img, dtype=np.float32)
            cy = mask.shape[0] // 2
            cx = mask.shape[1] // 2
            cv2.circle(mask, (cx,cy), radius, (1,1,1), -1)[0]
            mask = 1 - mask

            # high boost filter (sharpening) = 1 + fraction of high pass filter
            mask = 1 + 0.5*mask 

            # blur the mask
            mask2 = cv2.GaussianBlur(mask, (19,19), 0)

            # apply mask to dft_shift
            dft_shift_masked = np.multiply(dft_shift,mask)
            dft_shift_masked2 = np.multiply(dft_shift,mask2)

            # shift origin from center to upper left corner
            back_ishift = np.fft.ifftshift(dft_shift)
            back_ishift_masked = np.fft.ifftshift(dft_shift_masked)
            back_ishift_masked2 = np.fft.ifftshift(dft_shift_masked2)

            # do idft saving as complex output
            img_back = np.fft.ifft2(back_ishift, axes=(0,1))
            img_filtered = np.fft.ifft2(back_ishift_masked, axes=(0,1))
            img_filtered2 = np.fft.ifft2(back_ishift_masked2, axes=(0,1))

            # combine complex real and imaginary components to form (the magnitude for) the original image again
            img_back = np.abs(img_back).clip(0,255).astype(np.uint8)
            img_filtered = np.abs(img_filtered).clip(0,255).astype(np.uint8)
            img_filtered2 = np.abs(img_filtered2).clip(0,255).astype(np.uint8)

            # write result to disk
            cv2.imwrite("./Output images/Highpass_filtered.jpg", img_filtered2)
            pixmap = QPixmap("./Output images/Highpass_filtered.jpg")
            self.filter_filtered.setPixmap(pixmap)
            self.filter_filtered.setScaledContents(True)

######################################################################################################
    def histogram(self):
        img = cv2.imread(self.path,0)
        
        if self.greyscale.isChecked():
            #save greyscale image to show it in the gui
            im = Image.fromarray(img)
            im.save("./Output images/img.jpg")
            pixmap = QPixmap("./Output images/img.jpg")
            self.input_equalize.setPixmap(pixmap)
            self.input_equalize.setScaledContents(True) 

            img = np.asarray(img)
            # put pixels in a 1D array by flattening out img array
            flat = img.flatten()

            hist = get_histogram(flat, 256)
            plt.plot(hist)
            plt.savefig('./Output images/HistogramInput.jpg', bbox_inches='tight',pad_inches = 0)
            pixmap = QPixmap("./Output images/HistogramInput.jpg")
            self.input_histogram.setPixmap(pixmap)
            self.input_histogram.setScaledContents(True)

            plt.clf()

            # execute the fn
            cs = cumsum(hist)
            # re-normalize cumsum values to be between 0-255
            # numerator & denomenator
            nj = (cs - cs.min()) * 255
            N = cs.max() - cs.min()
            # re-normalize the cdf
            cs = nj / N
            # cast it back to uint8 since we can't use floating point values in images
            cs = cs.astype('uint8')

            img_new = cs[flat]

            hist = get_histogram(img_new, 256)
            # we see a much more evenly distributed histogram
            plt.plot(hist)
            plt.savefig('./Output images/HistogramOutput.jpg', bbox_inches='tight',pad_inches = 0)
            pixmap = QPixmap("./Output images/HistogramOutput.jpg")
            self.output_histogram.setPixmap(pixmap)
            self.output_histogram.setScaledContents(True)

            plt.clf()

            img_new = np.reshape(img_new, img.shape)
            plt.imshow(img_new, cmap='gray')
            plt.axis('off')

            plt.savefig('./Output images/Image after equalization.jpg', bbox_inches='tight',pad_inches = 0)
            pixmap = QPixmap("./Output images/Image after equalization.jpg")
            self.output_equalize.setPixmap(pixmap)
            self.output_equalize.setScaledContents(True)

            plt.clf()
            
        elif self.rgb.isChecked():
            
            pixmap = QPixmap(self.path)
            self.input_equalize.setPixmap(pixmap)
            self.input_equalize.setScaledContents(True) 

            
            image = skimage.io.imread(self.path)
            hist = get_histogram_rgb(image, 256)
            #print(len(hist))

            plt.title("Color Histogram")
            plt.xlabel("Color value")
            plt.ylabel("Pixel count")  

            colors = ("blue", "green", "red")
            for i , c in zip(hist, colors):
                plt.plot(i,color=c)
            plt.savefig('./Output images/1.jpg', bbox_inches='tight',pad_inches = 0)
            pixmap = QPixmap("./Output images/1.jpg")
            self.input_histogram.setPixmap(pixmap)
            self.input_histogram.setScaledContents(True)
            
            equalized = histogram_equalization_rgb(image)
            #print(len(equalized))

            image2 = skimage.io.imread('./Output images/output.jpg')
            pixmap = QPixmap("./Output images/output.jpg")
            self.output_equalize.setPixmap(pixmap)
            self.output_equalize.setScaledContents(True)
            
            hist = get_histogram_rgb(image2, 256)
            #print(len(hist))

            plt.clf()
            plt.figure(figsize=(6,4))
            plt.title("Color Histogram")
            plt.xlabel("Color value")
            plt.ylabel("Pixel count")  

            for i , c in zip(hist, colors):
                plt.plot(i,color=c)
            plt.savefig('./Output images/2.jpg', bbox_inches='tight',pad_inches = 0)
            pixmap = QPixmap("./Output images/2.jpg")
            self.output_histogram.setPixmap(pixmap)
            self.output_histogram.setScaledContents(True)
            plt.clf()
app = 0
app = QtWidgets.QApplication(sys.argv)
window = MainWindow()
app.exec_()        