from tkinter import *
from tkinter import Toplevel, messagebox, ttk, filedialog
from tkinter.ttk import Treeview
import pymysql
import pandas
import time
import random

root = Tk()
root.title('Student Management System')
root.config(bg="pink")
root.geometry('1174x700+200+50')
root.iconbitmap('student.ico')
root.resizable(False, False)

#------------------- Functions
def tick():
    time_string = time.strftime("%H:%M:%S")
    date_string = time.strftime("%d:%m:%Y")
    clock.config(text = 'Date: '+date_string+'\nTime: '+time_string)
    clock.after(100, tick)

colors = ['red','pink','green','yellow','crimson','red2','gold2']
def IntoLabelColorTick():
    fg = random.choice(colors)
    SliderLabel.config(fg = fg)
    SliderLabel.after(2, IntoLabelColorTick)


def IntoLabelTick():
    global count, text
    if count >= len(st):
        count, text = 0, ''
        SliderLabel.config(text=text)
    else:
        text += st[count]
        SliderLabel.config(text=text)
        count += 1
    SliderLabel.after(200,IntoLabelTick)


def Connectdb():
    def submitdb():
        global con, mycursor
        host = hostval.get()
        user = userval.get()
        password = passwordval.get()
        try:
            con = pymysql.connect(host=host, user=user, password=password)
            mycursor = con.cursor()
        except Exception as e:
            messagebox.showerror("Error", f'Data is incorrect...Please try again: {e}')
            return
        try:
            strr = 'create database studentmanagementsystem1'
            mycursor.execute(strr)
            strr = 'use studentmanagementsystem1'
            mycursor.execute(strr)
            strr = 'create table studentdata1(id int, name varchar(20), mobile varchar(13), email varchar(30), address varchar(100), gender varchar(10), dob varchar(50), date varchar(50), time varchar(50))'
            mycursor.execute(strr)
            strr = 'alter table studentdata1 modify column id int not null'
            mycursor.execute(strr)
            strr = 'alter table studentdata1 modify column id int primary key'
            mycursor.execute(strr)
            messagebox.showinfo("Success", "Database created & now you are connected to database.....", parent=dbroot)
        except:
            strr = 'use studentmanagementsystem1'
            mycursor.execute(strr)
            messagebox.showinfo("Success", "Now you are connected to database.....", parent=dbroot)
        dbroot.destroy()

    dbroot = Toplevel()
    dbroot.grab_set()
    dbroot.geometry("470x250+800+230")
    dbroot.title("Connect to Database")
    dbroot.iconbitmap('Student2.ico')
    dbroot.resizable(False, False)
    dbroot.config(bg = "blue")

    #------------------ Connectdb Labels --------------------------------------
    hostlabel =Label(dbroot, text = "Enter Host:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3, width = 13, anchor = 'w')
    hostlabel.place(x=10, y=10)

    userlabel =Label(dbroot, text = "Enter User:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3, width = 13, anchor = 'w')
    userlabel.place(x=10, y=70)

    passwordlabel =Label(dbroot, text = "Enter Password:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3, width = 13, anchor = 'w')
    passwordlabel.place(x=10, y=130)

    #------------------ Connectdb Entry --------------------------------------
    hostval = StringVar()
    userval = StringVar()
    passwordval = StringVar()

    hostentry = Entry(dbroot, font = "roman 15 bold", bd = 5, textvariable = hostval)
    hostentry.place(x=250, y=10)

    userentry = Entry(dbroot, font = "roman 15 bold", bd = 5, textvariable = userval)
    userentry.place(x=250, y=70)

    passwordentry = Entry(dbroot, font = "roman 15 bold", bd = 5, textvariable = passwordval)
    passwordentry.place(x=250, y=130)

    #---------------- Connectdb Button --------------------------------------------
    submitbutton = Button(dbroot, text = 'Submit', font = "roman 15 bold", width = 20, bg = "green", bd = 5,
                          activebackground="red", activeforeground="yellow", command=submitdb)
    submitbutton.place(x=150,y=190)

    dbroot.mainloop()


col = ['red', 'pink', 'green', 'yellow', 'crimson', 'red2', 'gold2']
def FrontLabelColorTick():
    fg = random.choice(col)
    frontlabel.config(fg=fg)
    frontlabel.after(2, FrontLabelColorTick)

########################
def addstudent():
    def submitadd():
        id = idval.get()
        name = nameval.get()
        mobile = mobileval.get()
        email = emailval.get()
        address = addressval.get()
        gender = genderval.get()
        dob = dobval.get()
        addeddate = time.strftime("%d/%m/%Y")
        addedtime = time.strftime("%H:%M:%S")
        try:
            strr =  'insert into studentdata1 values(%s,%s,%s,%s,%s,%s,%s,%s,%s)'
            mycursor.execute(strr,(id,name,mobile,email,address,gender,dob,addeddate,addedtime))
            con.commit()
            res = messagebox.askyesnocancel("Notification", 'ID {} Name {} Added Successfully.....  and want to clean the form'.format(id, name),
                                            parent=addroot)
            if res == True:
                idval.set('')
                nameval.set('')
                mobileval.set('')
                emailval.set('')
                addressval.set('')
                genderval.set('')
                dobval.set('')
        except :
            messagebox.showerror("Error",'Id already Exixt...Try another Id', parent=addroot)
        strr = 'select * from studentdata1'
        mycursor.execute(strr)
        datas = mycursor.fetchall()
        studenttable.delete(*studenttable.get_children())
        for i in datas:
            vv = [i[0],i[1],i[2],i[3],i[4],i[5],i[6],i[7],i[8]]
            studenttable.insert('',END, values=vv)


    addroot = Toplevel(master=DataEntryFrame)
    addroot.grab_set()
    addroot.geometry("470x470+220+200")
    addroot.title("Add Students")
    addroot.iconbitmap('Student2.ico')
    addroot.resizable(False, False)
    addroot.config(bg = "light green")

    #------------------ Connectdb Labels --------------------------------------
    idlabel =Label(addroot, text = "Enter ID:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                   width = 13, anchor = 'w')
    idlabel.place(x=10, y=10)

    namelabel =Label(addroot, text = "Enter Name:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                     width = 13, anchor = 'w')
    namelabel.place(x=10, y=70)

    mobilelabel =Label(addroot, text = "Enter Mobile:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                       width = 13, anchor = 'w')
    mobilelabel.place(x=10, y=130)

    emaillabel =Label(addroot, text = "Enter Email:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                      width = 13, anchor = 'w')
    emaillabel.place(x=10, y=190)

    addresslabel =Label(addroot, text = "Enter Address:", bg = "gold2", font = "times 20 bold", relief = GROOVE,
                        borderwidth = 3, width = 13, anchor = 'w')
    addresslabel.place(x=10, y=250)

    genderlabel =Label(addroot, text = "Enter Gender:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                       width = 13, anchor = 'w')
    genderlabel.place(x=10, y=310)

    doblabel =Label(addroot, text = "Enter D.O.B:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                    width = 13, anchor = 'w')
    doblabel.place(x=10, y=370)

    #------------------ Connectdb Entry --------------------------------------
    idval = StringVar()
    nameval = StringVar()
    mobileval = StringVar()
    emailval = StringVar()
    addressval = StringVar()
    genderval = StringVar()
    dobval = StringVar()

    identry = Entry(addroot, font = "roman 15 bold", bd = 5, textvariable = idval)
    identry.place(x=250, y=10)

    nameentry = Entry(addroot, font = "roman 15 bold", bd = 5, textvariable = nameval)
    nameentry.place(x=250, y=70)

    mobileentry = Entry(addroot, font = "roman 15 bold", bd = 5, textvariable = mobileval)
    mobileentry.place(x=250, y=130)

    emailentry = Entry(addroot, font = "roman 15 bold", bd = 5, textvariable = emailval)
    emailentry.place(x=250, y=190)

    addressentry = Entry(addroot, font = "roman 15 bold", bd = 5, textvariable = addressval)
    addressentry.place(x=250, y=250)

    genderentry = Entry(addroot, font = "roman 15 bold", bd = 5, textvariable = genderval)
    genderentry.place(x=250, y=310)

    dobentry = Entry(addroot, font = "roman 15 bold", bd = 5, textvariable = dobval)
    dobentry.place(x=250, y=370)

    #---------------- Connectdb Button --------------------------------------------
    submitbtn = Button(addroot, text = 'Submit', font = "roman 15 bold", width = 20, bg = "green", bd = 5,
                          activebackground="red", activeforeground="yellow", command=submitadd)
    submitbtn.place(x=130,y=420)

    addroot.mainloop()

def searchstudent():
    def submitsearch():
        id = idval.get()
        name = nameval.get()
        mobile = mobileval.get()
        email = emailval.get()
        address = addressval.get()
        gender = genderval.get()
        dob = dobval.get()
        addeddate = time.strftime("%d/%m/%Y")

        if id != '':
            strr = 'select * from studentdata1 where id=%s'
            mycursor.execute(strr, (id))
            datas = mycursor.fetchall()
            studenttable.delete(*studenttable.get_children())
            for i in datas:
                vv = [i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7], i[8]]
                studenttable.insert('', END, values=vv)

        elif name != '':
            strr = 'select * from studentdata1 where name=%s'
            mycursor.execute(strr, (name))
            datas = mycursor.fetchall()
            studenttable.delete(*studenttable.get_children())
            for i in datas:
                vv = [i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7], i[8]]
                studenttable.insert('', END, values=vv)

        elif mobile != '':
            strr = 'select * from studentdata1 where mobile=%s'
            mycursor.execute(strr, (mobile))
            datas = mycursor.fetchall()
            studenttable.delete(*studenttable.get_children())
            for i in datas:
                vv = [i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7], i[8]]
                studenttable.insert('', END, values=vv)

        elif email != '':
            strr = 'select * from studentdata1 where email=%s'
            mycursor.execute(strr, (email))
            datas = mycursor.fetchall()
            studenttable.delete(*studenttable.get_children())
            for i in datas:
                vv = [i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7], i[8]]
                studenttable.insert('', END, values=vv)

        elif address != '':
            strr = 'select * from studentdata1 where address=%s'
            mycursor.execute(strr, (address))
            datas = mycursor.fetchall()
            studenttable.delete(*studenttable.get_children())
            for i in datas:
                vv = [i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7], i[8]]
                studenttable.insert('', END, values=vv)

        elif gender != '':
            strr = 'select * from studentdata1 where gender=%s'
            mycursor.execute(strr, (gender))
            datas = mycursor.fetchall()
            studenttable.delete(*studenttable.get_children())
            for i in datas:
                vv = [i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7], i[8]]
                studenttable.insert('', END, values=vv)

        elif dob != '':
            strr = 'select * from studentdata1 where dob=%s'
            mycursor.execute(strr, (dob))
            datas = mycursor.fetchall()
            studenttable.delete(*studenttable.get_children())
            for i in datas:
                vv = [i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7], i[8]]
                studenttable.insert('', END, values=vv)

        elif addeddate != '':
            strr = 'select * from studentdata1 where addeddate=%s'
            mycursor.execute(strr, (addeddate))
            datas = mycursor.fetchall()
            studenttable.delete(*studenttable.get_children())
            for i in datas:
                vv = [i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7], i[8]]
                studenttable.insert('', END, values=vv)


    searchroot = Toplevel(master=DataEntryFrame)
    searchroot.grab_set()
    searchroot.geometry("470x540+220+200")
    searchroot.title("Search Data")
    searchroot.iconbitmap('Student2.ico')
    searchroot.resizable(False, False)
    searchroot.config(bg = "red")

    #------------------ Connectdb Labels --------------------------------------
    idlabel =Label(searchroot, text = "Enter ID:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                   width = 13, anchor = 'w')
    idlabel.place(x=10, y=10)

    namelabel =Label(searchroot, text = "Enter Name:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                     width = 13, anchor = 'w')
    namelabel.place(x=10, y=70)

    mobilelabel =Label(searchroot, text = "Enter Mobile:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                       width = 13, anchor = 'w')
    mobilelabel.place(x=10, y=130)

    emaillabel =Label(searchroot, text = "Enter Email:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                      width = 13, anchor = 'w')
    emaillabel.place(x=10, y=190)

    addresslabel =Label(searchroot, text = "Enter Address:", bg = "gold2", font = "times 20 bold", relief = GROOVE,
                        borderwidth = 3, width = 13, anchor = 'w')
    addresslabel.place(x=10, y=250)

    genderlabel =Label(searchroot, text = "Enter Gender:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                       width = 13, anchor = 'w')
    genderlabel.place(x=10, y=310)

    doblabel =Label(searchroot, text = "Enter D.O.B:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                    width = 13, anchor = 'w')
    doblabel.place(x=10, y=370)

    datelabel =Label(searchroot, text = "Enter Date:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                    width = 13, anchor = 'w')
    datelabel.place(x=10, y=430)

    #------------------ Connectdb Entry --------------------------------------
    idval = StringVar()
    nameval = StringVar()
    mobileval = StringVar()
    emailval = StringVar()
    addressval = StringVar()
    genderval = StringVar()
    dobval = StringVar()
    dateval = StringVar()

    identry = Entry(searchroot, font = "roman 15 bold", bd = 5, textvariable = idval)
    identry.place(x=250, y=10)

    nameentry = Entry(searchroot, font = "roman 15 bold", bd = 5, textvariable = nameval)
    nameentry.place(x=250, y=70)

    mobileentry = Entry(searchroot, font = "roman 15 bold", bd = 5, textvariable = mobileval)
    mobileentry.place(x=250, y=130)

    emailentry = Entry(searchroot, font = "roman 15 bold", bd = 5, textvariable = emailval)
    emailentry.place(x=250, y=190)

    addressentry = Entry(searchroot, font = "roman 15 bold", bd = 5, textvariable = addressval)
    addressentry.place(x=250, y=250)

    genderentry = Entry(searchroot, font = "roman 15 bold", bd = 5, textvariable = genderval)
    genderentry.place(x=250, y=310)

    dobentry = Entry(searchroot, font = "roman 15 bold", bd = 5, textvariable = dobval)
    dobentry.place(x=250, y=370)

    dateentry = Entry(searchroot, font = "roman 15 bold", bd = 5, textvariable = dateval)
    dateentry.place(x=250, y=430)

    #---------------- Connectdb Button --------------------------------------------
    submitbtn = Button(searchroot, text = 'Submit', font = "roman 15 bold", width = 20, bg = "green", bd = 5,
                          activebackground="red", activeforeground="yellow", command=submitsearch)
    submitbtn.place(x=130,y=480)

    searchroot.mainloop()

def deletestudent():
    cc = studenttable.focus()
    content = studenttable.item(cc)
    pp = content['values'][0]
    strr = 'delete from studentdata1 where id = %s'
    mycursor.execute(strr, (pp))
    con.commit()
    messagebox.showinfo('Notification', 'Id {} deleted successfully...'.format(id))
    strr = 'select * from studentdata1'
    mycursor.execute(strr)
    datas = mycursor.fetchall()
    studenttable.delete(*studenttable.get_children())
    for i in datas:
        vv = [i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7], i[8]]
        studenttable.insert('', END, values=vv)


def updatestudent():
    def update():
        id = idval.get()
        name = nameval.get()
        mobile = mobileval.get()
        email = emailval.get()
        address = addressval.get()
        gender = genderval.get()
        dob = dobval.get()
        date = dateval.get()
        time = timeval.get()

        strr = 'update studentdata1 set name=%s, mobile=%s, email=%s, address=%s, gender=%s, dob=%s, date=%s,time=%s where id = %s'
        mycursor.execute(strr, (name, mobile, email, address, gender, dob, date, time, id))
        con.commit()
        messagebox.showinfo("Notification", "Id {} Modified Successfully.....".format(id),parent=updateroot)
        strr = 'select * from studentdata1'
        mycursor.execute(strr)
        datas = mycursor.fetchall()
        studenttable.delete(*studenttable.get_children())
        for i in datas:
            vv = [i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7], i[8]]
            studenttable.insert('', END, values=vv)


    updateroot = Toplevel(master=DataEntryFrame)
    updateroot.grab_set()
    updateroot.geometry("470x585+220+160")
    updateroot.title("Update Data")
    updateroot.iconbitmap('Student2.ico')
    updateroot.resizable(False, False)
    updateroot.config(bg = "orange3")

    #------------------ Connectdb Labels --------------------------------------
    idlabel =Label(updateroot, text = "Enter ID:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                   width = 13, anchor = 'w')
    idlabel.place(x=10, y=10)

    namelabel =Label(updateroot, text = "Update Name:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                     width = 13, anchor = 'w')
    namelabel.place(x=10, y=70)

    mobilelabel =Label(updateroot, text = "Update Mobile:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                       width = 13, anchor = 'w')
    mobilelabel.place(x=10, y=130)

    emaillabel =Label(updateroot, text = "Update Email:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                      width = 13, anchor = 'w')
    emaillabel.place(x=10, y=190)

    addresslabel =Label(updateroot, text = "Update Address:", bg = "gold2", font = "times 20 bold", relief = GROOVE,
                        borderwidth = 3, width = 13, anchor = 'w')
    addresslabel.place(x=10, y=250)

    genderlabel =Label(updateroot, text = "Update Gender:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                       width = 13, anchor = 'w')
    genderlabel.place(x=10, y=310)

    doblabel =Label(updateroot, text = "Update D.O.B:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                    width = 13, anchor = 'w')
    doblabel.place(x=10, y=370)

    datelabel =Label(updateroot, text = "Update Date:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                    width = 13, anchor = 'w')
    datelabel.place(x=10, y=430)

    timelabel =Label(updateroot, text = "Update Time:", bg = "gold2", font = "times 20 bold", relief = GROOVE, borderwidth = 3,
                    width = 13, anchor = 'w')
    timelabel.place(x=10, y=490)

    #------------------ Connectdb Entry --------------------------------------
    idval = StringVar()
    nameval = StringVar()
    mobileval = StringVar()
    emailval = StringVar()
    addressval = StringVar()
    genderval = StringVar()
    dobval = StringVar()
    dateval = StringVar()
    timeval = StringVar()

    identry = Entry(updateroot, font = "roman 15 bold", bd = 5, textvariable = idval)
    identry.place(x=250, y=10)

    nameentry = Entry(updateroot, font = "roman 15 bold", bd = 5, textvariable = nameval)
    nameentry.place(x=250, y=70)

    mobileentry = Entry(updateroot, font = "roman 15 bold", bd = 5, textvariable = mobileval)
    mobileentry.place(x=250, y=130)

    emailentry = Entry(updateroot, font = "roman 15 bold", bd = 5, textvariable = emailval)
    emailentry.place(x=250, y=190)

    addressentry = Entry(updateroot, font = "roman 15 bold", bd = 5, textvariable = addressval)
    addressentry.place(x=250, y=250)

    genderentry = Entry(updateroot, font = "roman 15 bold", bd = 5, textvariable = genderval)
    genderentry.place(x=250, y=310)

    dobentry = Entry(updateroot, font = "roman 15 bold", bd = 5, textvariable = dobval)
    dobentry.place(x=250, y=370)

    dateentry = Entry(updateroot, font = "roman 15 bold", bd = 5, textvariable = dateval)
    dateentry.place(x=250, y=430)

    timeentry = Entry(updateroot, font = "roman 15 bold", bd = 5, textvariable = timeval)
    timeentry.place(x=250, y=490)

    #---------------- Connectdb Button --------------------------------------------
    updatebtn = Button(updateroot, text = 'Submit', font = "roman 15 bold", width = 20, bg = "green", bd = 5,
                          activebackground="red", activeforeground="yellow", command=update)
    updatebtn.place(x=130,y=540)
    cc = studenttable.focus()
    content = studenttable.item(cc)
    pp = content['values']
    if len(pp) != 0:
        idval.set(pp[0])
        nameval.set(pp[1])
        mobileval.set(pp[2])
        emailval.set(pp[3])
        addressval.set(pp[4])
        genderval.set(pp[5])
        dobval.set(pp[6])
        dateval.set(pp[7])
        timeval.set(pp[8])


    updateroot.mainloop()

def showallstudent():
    strr = 'select * from studentdata1'
    mycursor.execute(strr)
    datas = mycursor.fetchall()
    studenttable.delete(*studenttable.get_children())
    for i in datas:
        vv = [i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7], i[8]]
        studenttable.insert('', END, values=vv)

def exportstudent():
    ff = filedialog.asksaveasfilename()
    gg = studenttable.get_children()
    id, name, mobile, email, address, gender, dob, addeddate, addedtime = [],[],[],[],[],[],[],[],[]
    for i in gg:
        content = studenttable.item(i)
        pp = content['values']
        id.append(pp[0]), name.append(pp[1]), mobile.append(pp[2]), email.append(pp[3]), address.append(pp[4]), gender.append(pp[5]),
        dob.append(pp[6]), addeddate.append(pp[7]), addedtime.append(pp[8])

    dd = ['ID', 'Name', 'Mobile No.', 'Email', 'Address', 'Gender', 'D.O.B', 'Added Date', 'Added Time']
    df = pandas.DataFrame(list(zip(id, name, mobile, email, address, gender, dob, addeddate, addedtime)), columns=dd)
    paths = r'{}.csv'.format(ff)
    df.to_csv(paths, index=False)
    messagebox.showinfo('Notification', 'Student Data is saved {}'.format(paths))

def exitstudent():
    res = messagebox.askyesnocancel("Notification", "Do you want to Exit ?")
    if res == True:
        root.destroy()

#------------------------------------------------------ Frames ----------------------------------------------------

#---------------------------------- Data Entry Frame -----------------------
DataEntryFrame = Frame(root, bg='crimson', relief = RIDGE, borderwidth = 5)
DataEntryFrame.place(x=10, y=80, width = 500, height = 600)

frontlabel = Label(DataEntryFrame, text = "                  Welcome                  ", width = 25,font = "times 30 italic bold", bg = "crimson")
frontlabel.pack(side=TOP, expand=True)
FrontLabelColorTick()

addbtn = Button(DataEntryFrame, text = "1. Add Student", width=25, font="roman 20 bold", bd=6, bg='skyblue3',
                activebackground="blue", relief = RIDGE, activeforeground="white", command = addstudent)
addbtn.pack(side=TOP, expand=True)

searchbtn = Button(DataEntryFrame, text = "2. Search Student", width=25, font="roman 20 bold", bd=6, bg='skyblue3',
                   activebackground="blue", relief = RIDGE, activeforeground="white", command=searchstudent)
searchbtn.pack(side=TOP, expand=True)

deletebtn = Button(DataEntryFrame, text = "3. Delete Student", width=25, font="roman 20 bold", bd=6, bg='skyblue3',
                   activebackground="blue", relief = RIDGE, activeforeground="white", command=deletestudent)
deletebtn.pack(side=TOP, expand=True)

updatebtn = Button(DataEntryFrame, text = "4. Update Student", width=25, font="roman 20 bold", bd=6, bg='skyblue3',
                   activebackground="blue", relief = RIDGE, activeforeground="white", command=updatestudent)
updatebtn.pack(side=TOP, expand=True)

showallbtn = Button(DataEntryFrame, text = "5. Show All", width=25, font="roman 20 bold", bd=6, bg='skyblue3',
                    activebackground="blue", relief = RIDGE, activeforeground="white", command=showallstudent)
showallbtn.pack(side=TOP, expand=True)

exportbtn = Button(DataEntryFrame, text = "6. Export Data", width=25, font="roman 20 bold", bd=6, bg='skyblue3',
                   activebackground="blue", relief = RIDGE, activeforeground="white", command=exportstudent)
exportbtn.pack(side=TOP, expand=True)

exitbtn = Button(DataEntryFrame, text = "7. Exit", width=25, font="roman 20 bold", bd=6, bg='skyblue3',
                 activebackground="blue", relief = RIDGE, activeforeground="white", command=exitstudent)
exitbtn.pack(side=TOP, expand=True)




#---------------------------------- Show Entry Frame  -----------------------------------------------

ShowDataFrame = Frame(root, bg='crimson', relief = RIDGE, borderwidth = 5)
ShowDataFrame.place(x=550, y= 80, width = 620, height = 600)

#--------------------------------  Show Data Frame
style = ttk.Style()
style.configure('Treeview.Heading',font="roman 15 bold", foreground='red')
style.configure('Treeview',font="times 15 bold", foreground='cyan')

scroll_x = Scrollbar(ShowDataFrame, orient=HORIZONTAL)
scroll_y = Scrollbar(ShowDataFrame, orient=VERTICAL)
studenttable = Treeview(ShowDataFrame, columns=('ID','Name','Mobile No.','Email','Address','Gender','D.O.B','Added Date',
                                                'Added Time'),xscrollcommand=scroll_x.set,yscrollcommand=scroll_y.set)
scroll_x.pack(side=BOTTOM, fill=X)
scroll_y.pack(side=RIGHT, fill=Y)
scroll_x.config(command=studenttable.xview)
scroll_y.config(command=studenttable.yview)
studenttable.heading('ID', text="ID")
studenttable.heading('Name', text="Name")
studenttable.heading('Mobile No.', text="Mobile No.")
studenttable.heading('Email', text="Email")
studenttable.heading('Address', text="Address")
studenttable.heading('Gender', text="Gender")
studenttable.heading('D.O.B', text="D.O.B")
studenttable.heading('Added Date', text="Added Date")
studenttable.heading('Added Time', text="Added Time")
studenttable['show'] = 'headings'
studenttable.column('ID', width=80)
studenttable.column('Name', width=150)
studenttable.column('Mobile No.', width=200)
studenttable.column('Email', width=220)
studenttable.column('Address', width=100)
studenttable.column('Gender', width=100)
studenttable.column('D.O.B', width=150)
studenttable.column('Added Date', width=150)
studenttable.column('Added Time', width=150)
studenttable.pack(fill=BOTH, expand=1)





#--------------- Slider -------------------------------------------------------
st = ' Student  Management  System'
count, text = 0, ''
###############

SliderLabel = Label(root, text = st,font = 'times 30 italic bold', relief = RIDGE, borderwidth = 5, width = 25, bg = "cyan")
SliderLabel.place(x=260, y= 0)
IntoLabelTick()
IntoLabelColorTick()

#-------------- Clock -----------------------------------------------------------
clock = Label(root,font = 'times 14 italic bold', relief = RIDGE, borderwidth = 4, bg = "light green")
clock.place(x=0, y= 0)
tick()

#------------- Connect to Database Button --------------------------------------
connectbutton = Button(root, text = "Connect To Database", width = 20,font = 'times 16 italic bold', relief = RIDGE,
                       borderwidth = 6, activebackground="red", activeforeground="yellow", bg = "green", command = Connectdb)
connectbutton.place(x=950, y=0)


root.mainloop()