from tkinter import *
import tkinter.messagebox
from tkinter import ttk
import random
import time
import datetime


def main():
    root = Tk()
    app = Window1(root)
    root.mainloop()

class Window1:
    def __init__(self, master):
        self.master = master
        self.master.title("Login System")
        self.master.geometry("1470x750+40+25")
        # self.master.geometry("1550x750+0+0")
        self.master.config(bg = "powder blue")
        self.frame = Frame(self.master, bg = "powder blue")
        self.frame.pack()

        self.Username = StringVar()
        self.Password = StringVar()

        self.lblTitle = Label(self.frame, text = "Login System", font = "arial 50 bold", bg = "powder blue", fg = "black")
        self.lblTitle.grid(row = 0, column = 0, columnspan = 2, pady = 40)

        #=============================================================================================

        self.LoginFrame1 = LabelFrame(self.frame, width = 1350, height = 600, font = "arial 20 bold", relief = RIDGE, bg = "cadet blue", bd = 20)
        self.LoginFrame1.grid(row = 1, column = 0)

        self.LoginFrame2 = LabelFrame(self.frame, width=1000, height=600, font="arial 20 bold", relief=RIDGE, bg="cadet blue", bd=20)
        self.LoginFrame2.grid(row=2, column=0)

        #===========================================Label and Entry==================================================

        self.lblUsername = Label(self.LoginFrame1, text = "Username", font = "arial 20 bold", bd = 22, bg = "cadet blue", fg = "Cornsilk")
        self.lblUsername.grid(row=0, column=0)
        self.txtUsername = Entry(self.LoginFrame1, font="arial 20 bold",bd = 7, textvariable = self.Username, width = 34)
        self.txtUsername.grid(row=0, column=1, padx = 119)

        self.lblPassword = Label(self.LoginFrame1, text="Password", font="arial 20 bold", bd = 22, bg = "cadet blue", fg = "Cornsilk")
        self.lblPassword.grid(row=1, column=0)
        self.txtPassword = Entry(self.LoginFrame1, font="arial 20 bold", show = "*", bd = 7, textvariable = self.Password, width = 34)
        self.txtPassword.grid(row=1, column=1, columnspan = 2, pady = 30)


        #============================================Buttons=======================================================

        self.btnLogin = Button(self.LoginFrame2, text = "Login", width = 17, font="arial 20 bold", command = self.Login_System)
        self.btnLogin.grid(row = 3, column = 0, pady = 20, padx = 8)

        self.btnReset = Button(self.LoginFrame2, text="Reset", width=17, font="arial 20 bold", command = self.Reset)
        self.btnReset.grid(row=3, column=1, pady = 20, padx = 8)

        self.btnExit = Button(self.LoginFrame2, text="Exit", width=17, font="arial 20 bold", command = self.iExit)
        self.btnExit.grid(row=3, column=2, pady = 20, padx = 8)

        #===============================================================================================================

    def Login_System(self):
        u = self.Username.get()
        p = self.Password.get()
        if (u == 'Akash Singh' and p == str(9794423031)):
            self.newWindow = Toplevel(self.master)
            self.app = Window2(self.newWindow)
        else:
            tkinter.messagebox.askyesno("Login System", "Please Try Again, Invalid Login Detail")
            self.Username.set("")
            self.Password.set("")
            self.txtUsername.focus()

    def Reset(self):
        self.Username.set("")
        self.Password.set("")
        self.txtUsername.focus()

    def iExit(self):
        self.iExit = tkinter.messagebox.askyesno("Login System", "Are You Sure")
        if self.iExit > 0:
            self.master.destroy()
        else:
            command = self.new_window
            return


    def new_window(self):
        self.newWindow = Toplevel(self.master)
        self.app = Window2(self.newWindow)

class Window2:
    def __init__(self, master):
        self.master = master
        self.master.title("Login System")
        # self.master.geometry("1550x750+0+0")
        self.master.geometry("1470x750+40+25")
        self.master.config(bg = "cadet blue")
        self.frame = Frame(self.master, bg = "powder blue")
        self.frame.pack()




if __name__ == '__main__':
    main()