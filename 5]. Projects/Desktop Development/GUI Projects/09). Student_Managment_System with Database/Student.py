from tkinter import *
from tkinter import ttk
import pymysql
from tkinter import messagebox


class Student():
    def __init__(self, root):
        self.root = root
        self.root.geometry("1544x848+0+0")
        # self.root.attributes('-fullscreen', True)
        self.root.title("Student Management System")
        self.root.config(bg = "pink")
        title = Label(self.root, text = "Student  Managment  System", relief = GROOVE, font = "times 40 bold", bg = "yellow", fg = "red", bd = 5).pack(side = TOP, fill = X)

        #========================================All  Variables==================================================================

        self.Roll_No_var = StringVar()
        self.name_var = StringVar()
        self.email_var = StringVar()
        self.gender_var = StringVar()
        self.contact_var = StringVar()
        self.dob_var = StringVar()
        self.search_by = StringVar()
        self.search_txt = StringVar()

        #=======================================Manage  Frame===================================================================

        Manage_Frame = Frame(self.root, bg = "crimson", bd = 5, relief = RIDGE)
        Manage_Frame.place(x = 5, y = 80 , width = 520, height = 700)

        m_title = Label(Manage_Frame, text = "Manage Student", bg = "crimson", fg = "white", font = "lusica 20 bold underline")
        m_title.grid(row=0,columnspan=2,pady=20)
        # m_title.place(x =150 ,  y= 15)

        lbl_roll = Label(Manage_Frame, text = "Roll No.", bg = "crimson", fg = "white", font = "times 20 bold")
        lbl_roll.grid(row=1,column=0,pady=10,padx=20,sticky="w")
        # lbl_roll.place(x = 25, y = 100)
        txt_Roll = Entry(Manage_Frame, textvariable = self.Roll_No_var, bd = 5, relief = GROOVE,  font = "times 20 bold")
        txt_Roll.grid(row=1,column=1,pady=10,padx=20,sticky="w")
        # lbl_roll.place(x = 210, y = 100)

        lbl_name = Label(Manage_Frame, text = "Name", bg = "crimson", fg = "white", font = "times 20 bold")
        lbl_name.grid(row=2,column=0,pady=10,padx=20,sticky="w")
        # lbl_name.place(x = 25, y = 170)
        txt_name = Entry(Manage_Frame, textvariable = self.name_var, bd=5, relief=GROOVE, font="times 20 bold")
        txt_name.grid(row=2,column=1,pady=10,padx=20,sticky="w")
        # lbl_name.place(x=210, y=170)

        lbl_Email = Label(Manage_Frame, text = "Email", bg = "crimson", fg = "white", font = "times 20 bold")
        lbl_Email.grid(row=3,column=0,pady=10,padx=20,sticky="w")
        # lbl_mail.place(x = 25, y = 240)
        txt_Email = Entry(Manage_Frame, textvariable = self.email_var, bd=5, relief=GROOVE, font="times 20 bold")
        txt_Email.grid(row=3,column=1,pady=10,padx=20,sticky="w")
        # lbl_mail.place(x=210, y=240)

        lbl_Gender = Label(Manage_Frame, text = "Gender", bg = "crimson", fg = "white", font = "times 20 bold")
        lbl_Gender.grid(row=4,column=0,pady=10,padx=20,sticky="w")
        # lbl_gender.place(x = 25, y = 310)
        combo_gender = ttk.Combobox(Manage_Frame, textvariable = self.gender_var, font="times 20 bold", state="readonly")
        combo_gender['values'] = ("Male", "Female", "Other")
        combo_gender.grid(row=4,column=1,pady=10,padx=20)
        # combo_gender.place(x=210, y=310)

        lbl_Contact = Label(Manage_Frame, text = "Contact No.", bg = "crimson", fg = "white", font = "times 20 bold")
        lbl_Contact.grid(row=5,column=0,pady=10,padx=20,sticky="w")
        # lbl_Contact.place(x = 25, y = 380)
        txt_Contact = Entry(Manage_Frame, textvariable = self.contact_var, bd=5, relief=GROOVE, font="times 20 bold")
        txt_Contact.grid(row=5,column=1,pady=10,padx=20,sticky="w")
        # lbl_num.place(x=210, y = 380)

        lbl_Dob = Label(Manage_Frame, text = "D.O.B", bg = "crimson", fg = "white", font = "times 20 bold")
        lbl_Dob.grid(row=6,column=0,pady=10,padx=20,sticky="w")
        # lbl_dob.place(x = 25, y = 450)
        txt_Dob = Entry(Manage_Frame, textvariable = self.dob_var, bd=5, relief=GROOVE, font="times 20 bold")
        txt_Dob.grid(row=6,column=1,pady=10,padx=20,sticky="w")
        # lbl_dob.place(x=210, y=450)

        lbl_Address = Label(Manage_Frame, text = "Address", bg = "crimson", fg = "white", font  = "times 20 bold")
        lbl_Address.grid(row=7,column=0,pady=10,padx=20,sticky="w")
        # lbl_Address.place(x = 25, y = 520)
        self.txt_Address = Text(Manage_Frame, bd=5, relief=GROOVE, font="times 20 bold", width = 20, height = 3)
        self.txt_Address.grid(row=7,column=1,pady=10,padx=20,sticky="w")
        # self.txt_Address.place(x= 210, y=500)

        # =======================================Button  Frame===================================================================

        b1 = Button(Manage_Frame, text = "Add", bd = 7, bg = "cyan", fg = "black", activebackground="green", font = "times 25 bold", command = self.add_students)
        b1.place(x = 10, y = 615)

        b2 = Button(Manage_Frame, text="Update", bd = 7, bg="cyan", fg="black", activebackground="green", font="times 25 bold", command = self.update_data)
        b2.place(x=115, y=615)

        b3 = Button(Manage_Frame, text="Delete", bd = 7, bg="cyan", fg="black", activebackground="green", font="times 25 bold", command = self.delete_data)
        b3.place(x=260, y=615)

        b4 = Button(Manage_Frame, text="Clear", bd = 7, bg="cyan", fg="black", activebackground="green", font="times 25 bold", command = self.clear)
        b4.place(x=390, y=615)

        #=======================================Detail  Frame===================================================================

        Detail_Frame = Frame(self.root, bg = "crimson", bd = 5, relief = RIDGE)
        Detail_Frame.place(x = 530, y = 80, width = 990, height = 700)

        lbl_search = Label(Detail_Frame, text="Search  By --", bg="crimson", fg="white", font="times 20 bold")
        lbl_search.grid(row=0,column=0,pady=10,padx=20,sticky="w")
        # lbl_search.place(x=5, y=5)

        combo_search = ttk.Combobox(Detail_Frame, textvariable = self.search_by, width =12, font="times 20 bold", state="readonly")
        combo_search['values'] = ("Roll_No", "Name", "Contact")
        combo_search.grid(row=0,column=1,pady=10,padx=20)
        # combo_search.place(x=170, y=5)

        txt_search = Entry(Detail_Frame, textvariable = self.search_txt, width =12, bd=4, relief=GROOVE, font="times 20 bold")
        txt_search.grid(row=0,column=2,pady=10,padx=20,sticky="w")
        # txt_search.place(x= 400, y=5)

        b5 = Button(Detail_Frame, text="Search", bg="cyan", fg="black", activebackground="green", width = 8, bd =12, font="times 20 bold", command = self.search_data)
        b5.grid(row=0,column=3,pady=10,padx=10)
        # b5.place(x=620, y=4)

        b6 = Button(Detail_Frame, text="Show All", bg="cyan", fg="black", activebackground="green", width = 9, bd = 12, font="times 20 bold", command = self.fetch_data)
        b6.grid(row=0,column=4,pady=10,padx=10)
        # b6.place(x=790, y=4)

        #=======================================Table  Frame===================================================================

        Table_Frame = Frame(Detail_Frame, bg = "green", bd = 6, relief = RIDGE)
        Table_Frame.place(x = 5, y = 80, width = 970, height = 605)

        scroll_x = Scrollbar(Table_Frame, orient = HORIZONTAL)
        scroll_x.pack(side=BOTTOM, fill=X)
        scroll_y = Scrollbar(Table_Frame, orient = VERTICAL)
        scroll_y.pack(side=RIGHT, fill=Y)
        self.Student_table = ttk.Treeview(Table_Frame, columns = ("roll", "name", "email", "gender", "contact", "dob", "Address"), xscrollcommand = scroll_x.set, yscrollcommand = scroll_y.set)
        scroll_x.config(command = self.Student_table.xview)
        scroll_y.config(command = self.Student_table.yview)
        self.Student_table.heading("roll", text = "Roll No.")
        self.Student_table.heading("name", text="Name")
        self.Student_table.heading("email", text="Email")
        self.Student_table.heading("gender", text="Gender")
        self.Student_table.heading("contact", text="Contact No.")
        self.Student_table.heading("dob", text="D.O.B")
        self.Student_table.heading("Address", text="Address")

        self.Student_table['show'] = "headings"
        self.Student_table.column ("roll", width = 50)
        self.Student_table.column("name", width=100)
        self.Student_table.column("email", width = 150)
        self.Student_table.column("gender", width=70)
        self.Student_table.column("contact", width=80)
        self.Student_table.column("dob", width=100)
        self.Student_table.column("Address", width=100)
        self.Student_table.pack(fill = BOTH, expand = 1)
        self.Student_table.bind("<ButtonRelease-1>", self.get_cursor)
        self.fetch_data()

    def add_students(self):
        if self.Roll_No_var.get() == "" or self.name_var.get() == "" or self.email_var.get() == "" or self.gender_var.get() == "" or  self.contact_var.get() == "" or self.dob_var.get()=="":
            messagebox.showerror("Error", "All fields are required!!")
        else:
            con = pymysql.connect(host = "localhost", user = "root", password = "", database = "student_system")
            cur = con.cursor()
            # cur.execute(f"insert into students values({self.Roll_No_var.get()}, {self.name_var.get()}, {self.email_var.get()},{self.gender_var.get()}, {self.contact_var.get()}, {self.dob_var.get()}, {self.txt_Address.get('1.0', END)})")
            cur.execute("insert into students values(%s,%s,%s,%s,%s,%s,%s)", (self.Roll_No_var.get(), self.name_var.get(), self.email_var.get(), self.gender_var.get(), self.contact_var.get(), self.dob_var.get(), self.txt_Address.get('1.0', END)))

            con.commit()
            self.fetch_data()
            self.clear()
            con.close()
            messagebox.showinfo("Success", "Record has been inserted")

    def fetch_data(self):
        con = pymysql.connect(host="localhost", user="root", password="", database="student_system")
        cur = con.cursor()
        cur.execute("select * from students")
        rows = cur.fetchall()
        if len(rows)!=0:
            self.Student_table.delete(*self.Student_table.get_children())
            for row in rows:
                self.Student_table.insert("", END, values = row)
            con.commit()
        con.close()

    def clear(self):
        self.Roll_No_var.set("")
        self.name_var.set("")
        self.email_var.set("")
        self.gender_var.set("")
        self.contact_var.set("")
        self.dob_var.set("")
        self.txt_Address.delete("1.0", END)

    def get_cursor(self, event):
        cursor_row = self.Student_table.focus()
        contents = self.Student_table.item(cursor_row)
        row = contents['values']
        self.Roll_No_var.set(row[0])
        self.name_var.set(row[1])
        self.email_var.set(row[2])
        self.gender_var.set(row[3])
        self.contact_var.set(row[4])
        self.dob_var.set(row[5])
        self.txt_Address.delete("1.0", END)
        self.txt_Address.insert(END, row[6])

    def delete_data(self):
        con = pymysql.connect(host = "localhost", user = "root", password = "", database = "student_system")
        cur = con.cursor()
        try:
            # cur.execute(f"delete from students where roll_No = {self.Roll_No_var.get()}")
            cur.execute("delete from students where roll_No = %s", self.Roll_No_var.get())
            con.commit()
        except Exception as e:
            print(e)
        finally:
            con.close()
            self.fetch_data()
            self.clear()

    def update_data(self):
        con = pymysql.connect(host = "localhost", user = "root", password = "", database = "student_system")
        cur = con.cursor()
        try:
            # cur.execute(f"update students set name = {self.name_var.get()}, email = {self.email_var.get()}, gender = {self.gender_var.get()}, contact= {self.contact_var.get()}, dob = {self.dob_var.get()}, address = {self.txt_Address.get('1.0', END)}  where roll_no = {self.Roll_No_var.get()}")
            cur.execute("update students set name = %s, email = %s, gender = %s, contact= %s, dob = %s, address = %s  where roll_no = %s",(self.name_var.get(),self.email_var.get(),self.gender_var.get(),self.contact_var.get(),self.dob_var.get(),self.txt_Address.get('1.0', END),self.Roll_No_var.get()))
            con.commit()
        except Exception as e:
            print(e)
        finally:
            self.fetch_data()
            self.clear()
            con.close()

    def search_data(self):
        con = pymysql.connect(host="localhost", user="root", password="", database="student_system")
        cur = con.cursor()
        try:
            cur.execute("select * from students where " + str(self.search_by.get()) + " LIKE '%"  + str(self.search_txt.get()) + "%'")
            rows = cur.fetchall()
            if len(rows)!=0:
                self.Student_table.delete(*self.Student_table.get_children())
                for row in rows:
                   self.Student_table.insert("", END, values = row)
                con.commit()
        except Exception as e:
            print(e)
        finally:
            con.close()

if __name__ == '__main__':
    root = Tk()
    obj = Student(root)
    root.mainloop()
