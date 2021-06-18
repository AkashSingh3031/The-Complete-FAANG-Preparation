from tkinter import *
from PIL import Image, ImageTk, ImageDraw
from math import *
import time
from datetime import *
import pymysql
from tkinter import messagebox, ttk

class Login:
    def __init__(self,root):
        self.root = root
        self.root.title("Login Window")
        self.root.geometry("1470x750+40+25")
        # self.root.geometry("1530x790+0+0")
        self.root.config(bg="#021e2f")


        #---------------------BACKGROUND COLORS---------------------
        left_lbl = Label(self.root, bg="#08A3D2",bd=0)
        left_lbl.place(x=0,y=0,width=700,relheight=1)
        
        right_lbl = Label(self.root, bg="#031F3C",bd=0)
        right_lbl.place(x=600,y=0,relwidth=1,relheight=1)

        #---------------------FRAMES-----------------------------------
        login_frame = Frame(self.root,bg="white")
        login_frame.place(x=350, y=125, width=800, height=550)

        title = Label(login_frame, text="LOGIN HERE", font="times 30 bold", bg="white", fg="#08A3D2").place(x=250, y=50)

        email = Label(login_frame, text="EMAIL ADDRESS", font="times 18 bold", bg="white", fg="gray").place(x=250, y=150)
        self.txt_email = Entry(login_frame, font="times 15", bg="light gray")
        self.txt_email.place(x=250, y=180, width=350, height=35)
        
        pass_ = Label(login_frame, text="PASSWORD", font="times 18 bold", bg="white", fg="gray").place(x=250, y=250)
        self.txt_pass_ = Entry(login_frame, font="times 15", bg="light gray", show = "*")
        self.txt_pass_.place(x=250, y=280, width=350, height=35)

        btn_reg = Button(login_frame, text="Register New Account?", font="times 14", command=self.register_window, bd=0, bg="white", fg="#B00857", cursor='hand2').place(x=250, y=320)
        btn_reg = Button(login_frame, text="Forget Password?", font="times 14", command=self.forget_password_window, bd=0, bg="white", fg="red", cursor='hand2').place(x=450, y=320)
        
        btn_login = Button(login_frame, text="Login", font="times 20 bold", command=self.login, fg="white", bg="#B00857", cursor='hand2').place(x=250, y=380, width=180, height=40)



        #------------CLOCK---------------
        self.lbl = Label(self.root,text="\nAnalog Clock",font="times 30 bold",compound=BOTTOM,fg="white",bg="black",bd=0)
        self.lbl.place(x=90,y=150,height=500,width=450)

        self.working()
        
    def clock_image(self,hr,min_,sec_):
        clock = Image.new("RGB",(400,400),(0, 0, 0))
        draw = ImageDraw.Draw(clock)
        #---------For Clock Image--------------
        bg = Image.open("images/c.jpg")
        bg = bg.resize((300,300), Image.ANTIALIAS)
        clock.paste(bg,(50,50))

        #===========Hour Line
        origin = 200,200
        draw.line((origin,200+50*sin(radians(hr)),200-50*cos(radians(hr))),fill="#DF005E",width=4)

        #===========Min Line
        draw.line((origin,200+80*sin(radians(min_)),200-80*cos(radians(min_))),fill="white",width=3)

        #===========Sec Line
        draw.line((origin,200+100*sin(radians(sec_)),200-100*cos(radians(sec_))),fill="yellow",width=2)
        draw.ellipse((195,195,210,210), fill="#1AD5D5")
        clock.save("images/clock_new.png")

    def register_window(self):
        self.root.destroy()
        import register

    def reset(self):
        self.cmb_quest.current(0)
        self.txt_answer.delete(0,END)
        self.txt_email.delete(0,END)
        self.txt_pass_.delete(0,END)
        self.txt_new_pass.delete(0,END)

    def forget_password(self):
        if self.cmb_quest.get()=="Select" or self.txt_answer.get()=='' or self.txt_new_pass.get()=='':
            messagebox.showerror('Error', 'All fields are required', parent=self.root2)
        else:
            try:
                con = pymysql.connect(host='localhost', user='root', password='', database='register')
                cur = con.cursor()
                cur.execute("select * from register2 where email=%s and question=%s and answer=%s", (self.txt_email.get(), self.cmb_quest.get(), self.txt_answer.get()))
                row = cur.fetchone()
                if row == None:
                    messagebox.showerror("Error", 'Please Select the Correct Security Question / Enter Answer', parent=self.root2)
                else:
                    cur.execute("update register2 set password=%s where email=%s", (self.txt_new_pass.get(), self.txt_email.get()))
                    con.commit()
                    con.close()
                    messagebox.showinfo('Success', 'Your Password has been Reset, \nPlease Login with new Password.', parent=self.root2)
                    self.reset()
                    self.root2.destroy()
            except Exception as e:
                messagebox.showerror("Error", f'Error due to: {str(e)}', parent=self.root)

    def forget_password_window(self):
        if self.txt_email.get() == '':
            messagebox.showerror("Error", 'Please enter Email to reset your password.', parent=self.root)
        else:
            try:
                con = pymysql.connect(host='localhost', user='root', password='', database='register')
                cur = con.cursor()
                cur.execute("select * from register2 where email=%s", self.txt_email.get())
                row = cur.fetchone()
                if row == None:
                    messagebox.showerror("Error", 'Please enter valid Email to reset your password.', parent=self.root)
                else:
                    con.close()
                    self.root2 = Toplevel()
                    self.root2.title("Forget Password")
                    self.root2.geometry("350x400+600+200")
                    self.root2.config(bg='white')
                    self.root2.focus_force()
                    self.root2.grab_set()

                    t = Label(self.root2, text='Forget Password', font='times 20 bold', bg='white', fg='red').place(x=0, y=10, relwidth=1)

                    #----------------FORGET PASSWORD-------------------
                    question = Label(self.root2, text="Select Security Question", font="times 15 bold", bg="white", fg="gray").place(x=50, y=100)
                    self.cmb_quest = ttk.Combobox(self.root2, font="times 13", state="readonly", justify=CENTER)
                    self.cmb_quest['values']=("Select", "Your Birth Place", "Your Best Friend", "Your Best Book")
                    self.cmb_quest.place(x=50, y=130, width=250)
                    self.cmb_quest.current(0)
                    
                    answer = Label(self.root2, text="Security Answer", font="times 15 bold", bg="white", fg="gray").place(x=50, y=180)
                    self.txt_answer = Entry(self.root2, font="times 15", bg="lightgray")
                    self.txt_answer.place(x=50, y=210, width=250)

                    
                    new_pass = Label(self.root2, text="New Password", font="times 15 bold", bg="white", fg="gray").place(x=50, y=260)
                    self.txt_new_pass = Entry(self.root2, font="times 15", bg="lightgray")
                    self.txt_new_pass.place(x=50, y=290, width=250)   

                    btn_change_pass = Button(self.root2, text='Reset Password', command=self.forget_password, bg='green', fg='white', font='times 15 bold').place(x=80, y=340)     

            except Exception as e:
                messagebox.showerror("Error", f'Error due to: {str(e)}', parent=self.root)

    def login(self):
        if self.txt_email=='' or self.txt_pass_=='':
            messagebox.showerror('Error', 'All fields are requird...', parent=self.root)
        else:
            try:
                con = pymysql.connect(host='localhost', user='root', password='', database='register')
                cur = con.cursor()
                cur.execute("select * from register2 where email=%s and password=%s", (self.txt_email.get(), self.txt_pass_.get()))
                row = cur.fetchone()
                if row == None:
                    messagebox.showerror("Error", 'Invalid USER  &  PASSWORD', parent=self.root)
                else:
                    messagebox.showinfo("Success", "Welcome", parent=self.root)
                con.close()
            except Exception as e:
                messagebox.showerror("Error", f'Error due to: {str(e)}', parent=self.root)



    def working(self):
        h=datetime.now().time().hour
        m=datetime.now().time().minute
        s=datetime.now().time().second

        hr=(h/12)*360
        min_=(m/60)*360
        sec_=(s/60)*360

        self.clock_image(hr,min_,sec_)
        self.img=ImageTk.PhotoImage(file="images/clock_new.png")
        self.lbl.config(image=self.img)
        self.lbl.after(200,self.working)



root = Tk()
obj = Login(root)
root.mainloop()