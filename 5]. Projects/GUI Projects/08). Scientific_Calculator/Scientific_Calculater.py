from tkinter import *
from tkinter import messagebox as tmsg
import math
import tkinter.messagebox

root = Tk()
root.title("Scientific Calculater--")
root.wm_iconbitmap("cal.ico")
root.configure(background = "powder blue")
root.geometry("495x590+40+40")
root.resizable(width=False, height=False)

calc = Frame(root)
calc.grid()

class Calc():
    def __init__(self):
        self.total = 0
        self.current = ""
        self.input_value = True
        self.check_sum = False
        self.op = ""
        self.result = False

    def numberEnter(self, num):
            self.result = False
            firstnum = txtDisplay.get()
            secondnum = str(num)
            if self.input_value:
                self.current = secondnum
                self.input_value = False
            else:
                if secondnum == '.':
                    if secondnum in firstnum:
                        return
                self.current = firstnum + secondnum
            self.display(self.current)

    def sum_of_total(self):
            self.result = True
            self.current = float(self.current)
            if self.check_sum == True:
                self.valid_function()
            else:
                self.total = float(txtDisplay.get())

    def display(self, value):
            txtDisplay.delete(0, END)
            txtDisplay.insert(0, value)

    def valid_function(self):
            if self.op == "add":
                self.total += self.current
            if self.op == "sub":
                self.total -= self.current
            if self.op == "multi":
                self.total *= self.current
            if self.op == "divide":
                self.total /= self.current
            if self.op == "mod":
                self.total %= self.current
            self.input_value = True
            self.check_sum = False
            self.display(self.total)

    def operation(self, op):
            self.current = float(self.current)
            if self.check_sum:
                self.valid_function()
            elif not self.result:
                self.total = self.current
                self.input_value = True
            self.check_sum = True
            self.op = op
            self.result = False

    def pi(self):
            self.result = False
            self.current = math.pi
            self.display(self.current)

    def tau(self):
            self.result = False
            self.current = math.tau
            self.display(self.current)

    def e(self):
            self.result = False
            self.current = math.e
            self.display(self.current)

    def cos(self):
            self.result = False
            self.current = math.cos(math.radians(float(txtDisplay.get())))
            self.display(self.current)

    def tan(self):
            self.result = False
            self.current = math.tan(math.radians(float(txtDisplay.get())))
            self.display(self.current)

    def sin(self):
            self.result = False
            self.current = math.sin(math.radians(float(txtDisplay.get())))
            self.display(self.current)

    def cosh(self):
            self.result = False
            self.current = math.cosh(math.radians(float(txtDisplay.get())))
            self.display(self.current)

    def tanh(self):
            self.result = False
            self.current = math.tanh(math.radians(float(txtDisplay.get())))
            self.display(self.current)

    def sinh(self):
            self.result = False
            self.current = math.sinh(math.radians(float(txtDisplay.get())))
            self.display(self.current)

    def acosh(self):
            self.result = False
            self.current = math.acosh(float(txtDisplay.get()))
            self.display(self.current)

    def atanh(self):
            try:
                self.result = False
                self.current = math.atanh(float(txtDisplay.get()))
                self.display(self.current)
            except:
                pass

    def asinh(self):
            self.result = False
            self.current = math.asinh(float(txtDisplay.get()))
            self.display(self.current)

    def log(self):
            self.result = False
            self.current = math.log(float(txtDisplay.get()))
            self.display(self.current)

    def log2(self):
            self.result = False
            self.current = math.log2(float(txtDisplay.get()))
            self.display(self.current)

    def log10(self):
            self.result = False
            self.current = math.log10(float(txtDisplay.get()))
            self.display(self.current)

    def exp(self):
            self.result = False
            self.current = math.exp(float(txtDisplay.get()))
            self.display(self.current)

    def expm1(self):
            self.result = False
            self.current = math.expm1(float(txtDisplay.get()))
            self.display(self.current)

    def log1p(self):
            self.result = False
            self.current = math.log1p(float(txtDisplay.get()))
            self.display(self.current)

    def degrees(self):
            self.result = False
            self.current = math.degrees(float(txtDisplay.get()))
            self.display(self.current)

    def lgamma(self):
            self.result = False
            self.current = math.lgamma(float(txtDisplay.get()))
            self.display(self.current)

    def Clear_Entry(self):
            try:
                self.current = self.current[:-1]
                self.display(self.current)
            except:
                    print("Float value Result not clear")
            
    def all_Clear_Entry(self):
            self.result = False
            self.current = "0"
            self.display(0)
            self.input_value = True
        
    def MathsPM(self):
            self.result = False
            self.current = -(float(txtDisplay.get()))
            self.display(self.current)

    def squared(self):
            self.result = False
            self.current = math.sqrt(float(txtDisplay.get()))
            self.display(self.current)

    def factorial(self):
        try:
            self.result = False
            self.current = math.factorial(int(txtDisplay.get()))
            self.display(self.current)
        except Exception:
            print("Floting Numbers Can Not return factorials")

    def fabs(self):
            self.result = False
            self.current = math.fabs(float(txtDisplay.get()))
            self.display(self.current)

    def radians(self):
            self.result = False
            self.current = math.radians(float(txtDisplay.get()))
            self.display(self.current)

    #============================================Testing===================================

    def pow(self, x, y):
            self.result = False
            self.current = math.pow(int(txtDisplay.get()), int(txtDisplay.get()))
            self.display(self.current)

    #=======================================================================================

added_value = Calc()

txtDisplay = Entry(calc, font = "arial 20 bold", bg = "powder blue",bd = 30, width = 29, justify = RIGHT)
txtDisplay.grid(row = 0, column = 0, columnspan = 4, pady = 1)
txtDisplay.insert(0, "0")

numberpad = "789456123"
i = 0
btn = []
for j in range(2, 5):
    for k in range(3):
        btn.append(Button(calc, width = 6, height = 2, font ="arial  20  bold", bd = 4, text = numberpad[i]))
        btn[i].grid(row =j, column = k, pady = 1)
        btn[i]["command"] = lambda X = numberpad[i]: added_value.numberEnter(X)
        i += 1

#====================================Testing=================================================================

btnpow = Button(calc, text = "pow", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.pow)
btnpow.grid(row =3, column = 8, pady = 1)

# btnComma = Button(calc, text = "(", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue",command = lambda: added_value.numberEnter("("))
# btnComma.grid(row =1, column = 9, pady = 1)

# btnComma = Button(calc, text = ")", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue",command = lambda: added_value.numberEnter(")"))
# btnComma.grid(row =2, column = 9, pady = 1)

# btnComma = Button(calc, text = ",", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue",command = lambda: added_value.numberEnter(","))
# btnComma.grid(row =3, column = 9, pady = 1)

#====================================STANDERED  CALCULATER==============================================================

btnClar = Button(calc, text = chr(67), width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "red", command = added_value.Clear_Entry)
btnClar.grid(row =1, column = 0, pady = 1)

btnAllClar = Button(calc, text = chr(67) + chr(69), width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "red", command = added_value.all_Clear_Entry)
btnAllClar.grid(row =1, column = 1, pady = 1)

btnSq = Button(calc, text = "√", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.squared)
btnSq.grid(row =1, column = 2, pady = 1)

btnAdd = Button(calc, text = "+", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue",command = lambda: added_value.operation("add"))
btnAdd.grid(row =1, column = 3, pady = 1)

btnSub = Button(calc, text = "-", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue",command = lambda: added_value.operation("sub"))
btnSub.grid(row =2, column = 3, pady = 1)

btnMul = Button(calc, text = "*", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue",command = lambda: added_value.operation("multi"))
btnMul.grid(row =3, column = 3, pady = 1)

btnDiv = Button(calc, text = "÷", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue",command = lambda: added_value.operation("divide"))
btnDiv.grid(row =4, column = 3, pady = 1)

btnZero = Button(calc, text = "0", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue",command = lambda: added_value.numberEnter(0))
btnZero.grid(row =5, column = 0, pady = 1)

btnDot = Button(calc, text = ".", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue",command = lambda: added_value.numberEnter("."))
btnDot.grid(row =5, column = 1, pady = 1)

btnPM = Button(calc, text = "±", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.MathsPM)
btnPM.grid(row =5, column = 2, pady = 1)

btnEquals = Button(calc, text = "=", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue",command = added_value.sum_of_total)
btnEquals.grid(row =5, column = 3, pady = 1)

#===================================SCIENTIFIC  CALCULATION=============================================================
btnPi = Button(calc, text ="π" , width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.pi)
btnPi.grid(row =1, column = 4, pady = 1)

btncos = Button(calc, text = "cos", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.cos)
btncos.grid(row =1, column = 5, pady = 1)

btntan = Button(calc, text = "tan", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.tan)
btntan.grid(row =1, column = 6, pady = 1)

btnsin = Button(calc, text = "sin", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.sin)
btnsin.grid(row =1, column = 7, pady = 1)

btnfact = Button(calc, text = "x!", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.factorial)
btnfact.grid(row =1, column = 8, pady = 1)

# btnComma = Button(calc, text = "(", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue",command = lambda: added_value.numberEnter("("))
# btnComma.grid(row =1, column = 9, pady = 1)
#=======================================================================================================================
btn2Pi = Button(calc, text = "2π", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.tau)
btn2Pi.grid(row =2, column = 4, pady = 1)

btncosh = Button(calc, text = "cosh", width = 6, height = 2, font = "arial 20 bold", bd = 4, command = added_value.cosh)
btncosh.grid(row =2, column = 5, pady = 1)

btntanh = Button(calc, text = "tanh", width = 6, height = 2, font = "arial 20 bold", bd = 4, command = added_value.tanh)
btntanh.grid(row =2, column = 6, pady = 1)

btnsinh = Button(calc, text = "sinh", width = 6, height = 2, font = "arial 20 bold", bd = 4, command = added_value.sinh)
btnsinh.grid(row =2, column = 7, pady = 1)

btnfabs = Button(calc, text = "|x|", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.fabs)
btnfabs.grid(row =2, column = 8, pady = 1)

# btnComma = Button(calc, text = ")", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue",command = lambda: added_value.numberEnter(")"))
# btnComma.grid(row =2, column = 9, pady = 1)

#=======================================================================================================================
btnlog = Button(calc, text = "ln", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.log)
btnlog.grid(row =3, column = 4, pady = 1)

btnacosh = Button(calc, text = "acosh", width = 6, height = 2, font = "arial 20 bold", bd = 4, command = added_value.acosh)
btnacosh.grid(row =3, column = 5, pady = 1)

btnatanh = Button(calc, text = "atanh", width = 6, height = 2, font = "arial 20 bold", bd = 4, command = added_value.atanh)
btnatanh.grid(row =3, column = 6, pady = 1)

btnasinh = Button(calc, text = "asinh", width = 6, height = 2, font = "arial 20 bold", bd = 4, command = added_value.asinh)
btnasinh.grid(row =3, column = 7, pady = 1)

btnpow = Button(calc, text = "pow", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.pow)
btnpow.grid(row =3, column = 8, pady = 1)

# btnComma = Button(calc, text = ",", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue",command = lambda: added_value.numberEnter(","))
# btnComma.grid(row =3, column = 9, pady = 1)

#=======================================================================================================================
btnlog2 = Button(calc, text = "log2", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.log2)
btnlog2.grid(row =4, column = 4, pady = 1)

btnExp = Button(calc, text = "Exp", width = 6, height = 2, font = "arial 20 bold", bd = 4, command = added_value.exp)
btnExp.grid(row =4, column = 5, pady = 1)

btnMod = Button(calc, text = "%", width = 6, height = 2, font = "arial 20 bold", bd = 4, command = lambda: added_value.operation("mod"))
btnMod.grid(row =4, column = 6, pady = 1)

btnE = Button(calc, text = "e", width = 6, height = 2, font = "arial 20 bold", bd = 4, command = added_value.e)
btnE.grid(row =4, column = 7, pady = 1)

btndeg = Button(calc, text = "deg", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.degrees)
btndeg.grid(row =4, column = 8, pady = 1)

# btndeg = Button(calc, text = "deg", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.degrees)
# btndeg.grid(row =4, column = 9, pady = 1)

#=======================================================================================================================
btnlog10 = Button(calc, text = "log10", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.log10)
btnlog10.grid(row =5, column = 4, pady = 1)

btnlog1p = Button(calc, text = "log1p", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.log1p)
btnlog1p.grid(row =5, column = 5, pady = 1)

btnexpm1 = Button(calc, text = "expm1", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.expm1)
btnexpm1.grid(row =5, column = 6, pady = 1)

btnlgamma = Button(calc, text = "lgamma", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.lgamma)
btnlgamma.grid(row =5, column = 7, pady = 1)

btnrad = Button(calc, text = "rad", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.radians)
btnrad.grid(row =5, column = 8, pady = 1)

# btnrad = Button(calc, text = "rad", width = 6, height = 2, font = "arial 20 bold", bd = 4, bg = "powder blue", command = added_value.radians)
# btnrad.grid(row =5, column = 9, pady = 1)

#=======================================================================================================================
lblDisplay = Label(calc, text = "Scientific Calculater", font = "arial  46  bold", justify = CENTER)
lblDisplay.grid(row = 0, column = 4, columnspan =8)

#=======================================================================================================================


#======================================MENU  &  FUNCTION================================================================

def iExit():
    iExit = tkinter.messagebox.askyesno("Scientific Calculater", "Confirm if you want to exit")
    if iExit > 0:
        root.destroy()
        return

def Standered():
    root.resizable(width=False, height=False)
    root.geometry("495x568+40+40")
    
def Scientific():
    root.resizable(width=False, height=False)
    root.geometry("1085x568+40+40")

def help():
    print("I will help you")
    tmsg.showinfo("Help", "Code With Sky")

def rate():
    print("Rate us , Please!")
    val = tmsg.askquestion("How was your experience......."," was your experience Good ")
    if val == "yes":
        msg = "Greate!  Rate us Please."
    else:
        msg = "Tell us what went wrong"
    tmsg.showinfo("Experience",msg)

def about():
    pass


menubar = Menu(calc)

filemenu = Menu(menubar, tearoff = 0)
menubar.add_cascade(label  = "File", menu = filemenu)
filemenu.add_command(label = "Standered", command = Standered)
filemenu.add_command(label = "Scientific", command = Scientific)
filemenu.add_separator()
filemenu.add_command(label = "Exit", command = iExit )

editmenu = Menu(menubar, tearoff = 0)
menubar.add_cascade(label  = "Edit", menu = editmenu)
editmenu.add_command(label = "Cut")
editmenu.add_command(label = "Copy")
editmenu.add_separator()
editmenu.add_command(label = "Paste")

helpmenu = Menu(menubar, tearoff = 0)
menubar.add_cascade(label  = "Help", menu = helpmenu)
helpmenu.add_command(label = "Help", command = help)
helpmenu.add_command(label = "Rate", command = rate)
helpmenu.add_separator()
helpmenu.add_command(label = "About Creater", command = about)

root.config(menu = menubar)
root.mainloop()