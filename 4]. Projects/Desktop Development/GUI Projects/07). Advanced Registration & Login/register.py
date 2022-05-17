from tkinter import *
from PIL import Image,ImageTk
from tkinter import ttk, messagebox
import pymysql

class Register:
    def __init__(self,root):
        self.root = root
        self.root.title("Registation Window")
        # self.root.geometry("1530x790+0+0")
        self.root.geometry("1470x750+40+25")

        # BACKGROUND IMAGE
        self.bg = ImageTk.PhotoImage(file='images/bg.png')
        bg = Label(self.root, image=self.bg).place(x=250, y=0, relwidth=1, relheight=1)

        # LEFT IMAGE
        self.left = ImageTk.PhotoImage(file='images/side.png')
        left = Label(self.root, image=self.left).place(x=80, y=150, width=400, height=500)

        #REGISTER FRAME
        frame1 = Frame(self.root, bg="white")
        frame1.place(x=480,y=150,width=700,height=500)

        title = Label(frame1, text="REGISTER HERE", font="times 20 bold", bg="white", fg="green").place(x=50, y=30)
        
        f_name = Label(frame1, text="First Name", font="times 15 bold", bg="white", fg="gray").place(x=50, y=100)
        self.txt_fname = Entry(frame1, font="times 15", bg="lightgray")
        self.txt_fname.place(x=50, y=130, width=250)
        
        l_name = Label(frame1, text="Last Name", font="times 15 bold", bg="white", fg="gray").place(x=370, y=100)
        self.txt_lname = Entry(frame1, font="times 15", bg="lightgray")
        self.txt_lname.place(x=370, y=130, width=250)
        


        contact = Label(frame1, text="Contact No.", font="times 15 bold", bg="white", fg="gray").place(x=50, y=170)
        self.txt_contact = Entry(frame1, font="times 15", bg="lightgray")
        self.txt_contact.place(x=50, y=200, width=250)
        
        Email = Label(frame1, text="Email", font="times 15 bold", bg="white", fg="gray").place(x=370, y=170)
        self.txt_email = Entry(frame1, font="times 15", bg="lightgray")
        self.txt_email.place(x=370, y=200, width=250)
        


        question = Label(frame1, text="Select Security Question", font="times 15 bold", bg="white", fg="gray").place(x=50, y=240)
        self.cmb_quest = ttk.Combobox(frame1, font="times 13", state="readonly", justify=CENTER)
        self.cmb_quest['values']=("Select", "Your Birth Place", "Your Best Friend", "Your Best Book")
        self.cmb_quest.place(x=50, y=270, width=250)
        self.cmb_quest.current(0)
        
        answer = Label(frame1, text="Security Answer", font="times 15 bold", bg="white", fg="gray").place(x=370, y=240)
        self.txt_answer = Entry(frame1, font="times 15", bg="lightgray")
        self.txt_answer.place(x=370, y=270, width=250)
        


        password = Label(frame1, text="Password", font="times 15 bold", bg="white", fg="gray").place(x=50, y=310)
        self.txt_password = Entry(frame1, font="times 15", bg="lightgray")
        self.txt_password.place(x=50, y=340, width=250)
        
        cpassword = Label(frame1, text="Confirm Password", font="times 15 bold", bg="white", fg="gray").place(x=370, y=310)
        self.txt_cpassword = Entry(frame1, font="times 15", bg="lightgray")
        self.txt_cpassword.place(x=370, y=340, width=250)


        self.var_chk = IntVar()
        chk = Checkbutton(frame1, text="I Agree the Term & Condition", onvalue=1, offvalue=0, bg="white", font="times 12", variable=self.var_chk).place(x=50, y=380)

        self.btn_img = ImageTk.PhotoImage(file='images/register.png')
        btn_register = Button(frame1, image=self.btn_img, bd=0, cursor='hand2', command=self.register_data).place(x=50, y=420)
        btn_login = Button(self.root, text="Sign In", bd=0, cursor='hand2', command=self.login_window, font='times 20').place(x=230, y=540)

    def login_window(self):
        self.root.destroy()
        import login

    def clear(self):
        self.txt_fname.delete(0,END)
        self.txt_lname.delete(0,END)
        self.txt_contact.delete(0,END)
        self.txt_email.delete(0,END)
        self.cmb_quest.current(0)
        self.txt_answer.delete(0,END)
        self.txt_password.delete(0,END)
        self.txt_cpassword.delete(0,END)

    def register_data(self):
        if self.txt_fname.get()=='' or self.txt_contact.get()=='' or self.txt_email.get()=='' or self.cmb_quest.get()=='Select' or self.txt_answer.get()=='' or self.txt_password.get()=='' or self.txt_cpassword.get()=='':
            messagebox.showerror("Error", "All fields are required...", parent=self.root)
        
        elif self.txt_password.get() != self.txt_cpassword.get():
            messagebox.showerror("Error", 'Password and Confirm Password should be same', parent=self.root)

        elif self.var_chk.get() == 0:
            messagebox.showerror("Error", 'Please Agree Our Terms & Condition', parent=self.root)

        else:
            try:
                con = pymysql.connect(host='localhost', user='root', password='', database='register')
                cur = con.cursor()
                cur.execute("select * from register2 where email=%s", self.txt_email.get())
                row = cur.fetchone()
                if row != None:
                    messagebox.showerror("Error", 'User already Exist...\n Please try with another Email.', parent=self.root)
                else:
                    cur.execute("insert into register2 (f_name, l_name, contact, email, question, answer, password) values(%s, %s, %s, %s, %s, %s, %s)",
                                (
                                    self.txt_fname.get(),
                                    self.txt_lname.get(),
                                    self.txt_contact.get(),
                                    self.txt_email.get(),
                                    self.cmb_quest.get(),
                                    self.txt_answer.get(),
                                    self.txt_password.get(),
                                ))
                    con.commit()
                    con.close()
                    self.clear()
                    messagebox.showinfo("Success", "Register Successful", parent=self.root)
            except Exception as e:
                messagebox.showerror("Error", f'Error due to: {str(e)}', parent=self.root)




root = Tk()
obj = Register(root)
root.mainloop()