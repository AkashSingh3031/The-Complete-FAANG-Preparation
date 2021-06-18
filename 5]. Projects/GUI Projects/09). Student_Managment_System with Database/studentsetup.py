from cx_Freeze import *
import sys

includefiles = ["student.ico"]
excludes = []
packages = []
base = None

if sys.platform == 'win32':
    base = 'Win32GUI'

shortcut_table = [
    ("DesktopShortcut", #Shortcut
     "DesktopFolder",   #Directory_
     "Student_Data_Management_System",  #Name
     "TARGETDIR", #Component_
     "[TARGETDIR]\Student_Data_Management_System.exe", #Target
     None,  #Arguments
     None,  #Description
     None,  #Hotkey
     None,  #Iconḍḍ
     None,  #IconIndex
     None,  #ShowCmd
     "TARGETDIR",  #WkDir
    )
]

msi_data = {"Shortcut": shortcut_table}

bdist_msi_options = {"data": msi_data}
setup(
    version = "0.1",
    description = "Student_Data_Management_System By ---- AKASH SINGH",
    author = "Akash Singh",
    name = "Student Data Management System",
    options = {'build_exe': {'include_files': includefiles}, 'bdist_msi': bdist_msi_options,},
    executables = [
        Executable(
            script = "Student_Data_Management_System.py",
            base = base,
            icon = 'student.ico',
        )
    ]
)