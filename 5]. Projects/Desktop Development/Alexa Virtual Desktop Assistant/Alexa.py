#Author : Akash Khandelwal

#Importing Important Library
from pygame import mixer
import wolframalpha
import time
import pyautogui
import requests
import pyttsx3
import datetime
import wikipedia
import os
import webbrowser
import cv2
import random
import pyjokes
import speech_recognition as sr
from getpass import getpass
from requests import get

i = 1

#Set tone for listening
mixer.init()
mixer.music.load("demo.mpeg")
mixer.music.set_volume(0.7)

#Voices based Command
engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
#print(voices[1].id)# 0 for male and 1 for female
engine.setProperty('voice',voices[1].id)


#News based Function
def news():
     try:
      main_url = 'http://newsapi.org/v2/top-headlines?sources=the-times-of-india&apiKey=1e11213d2b9844e4948feee117eaec89'
      main_page = requests.get(main_url).json()
      articles = main_page["articles"]
      head = []
      day = ["first","second","third","fourth","fifth","sixth","seventh"]
      for ar in articles:
          head.append(ar['title'])

      for i in range(len(day)):
          speak(f"today's {day[i]} news is:{head[i]}")

     except Exception as e:
              speak("No Internet connection")

#Function for fecthing weather report
def Weather_Report(cityname):
     api_address = 'http://api.openweathermap.org/data/2.5/weather?appid=1ee020e53372311cc5131630c27b7427&q='


     url = api_address + cityname
     json_data = requests.get(url).json()


     if json_data['cod'] == '404':
         print("Invalid city:{}, Please check your city name".format(cityname))
     else:
         # Create Variable to store and display data
         temp_city = ((json_data['main']['temp']) - 273.15)
         weather_desc = json_data['weather'][0]['description']
         hmdt = json_data['main']['humidity']
         wind_spd = json_data['wind']['speed']
         date_time = datetime.datetime.now().strftime("%d %b %Y | %I:%M:%S %p")
         t = round(temp_city,2)
         print("-------------------------------------------------------------------")
         print("Weather Status for -{} || {}".format(cityname.upper(), date_time))
         print("-------------------------------------------------------------------")
         speak("Current temperature is "+str(t))
         speak("Current Weather desc is "+weather_desc)
         speak("Current Humidity is "+str(hmdt)+'%')
         speak("Current Wind Speed is "+str(wind_spd)+'kmph')

#Function for Speak audio
def speak(audio):
     print(audio)
     engine.say(audio)
     engine.runAndWait()

#Function for Greeting:-
def wishMe():
    speak("Intialzing Alexa")
    time.sleep(2)
    hour =int(datetime.datetime.now().hour)
    if hour>=0 and hour<12:
        speak("Good Morning Mr. Akash Khandelwal")
    elif hour>=12 and hour<18:
        speak("Good Afternoon Mr. Akash Khandelwal")

    else:

        speak("Good Evening Mr. Akash Khandelwal")

    date_time2 = datetime.datetime.now().strftime("%d %b %Y %I:%M %p")
    time.sleep(2)
    speak("Its "+date_time2)
    time.sleep(2)
    speak("I am Alexa Sir Your Virtual Assisstant 2.2.0 Please Tell me How may i help You")
    time.sleep(2)


#Function for Taking command From User
def takeCommand():
     # It takes Microphone input from user
     r = sr.Recognizer()
     with sr.Microphone() as source:
         print("Listening....")
         r.pause_threshold = 1
         audio = r.listen(source,phrase_time_limit=10)
     try:
         mixer.music.play()
         print("Reconinzing..........")
         #query = r.recognize_google(audio,language='en-in')
         query = r.recognize_google(audio, language='en-in')
         print(f"User Said:{query}\n")
         time.sleep(2)
         mixer.music.stop()
     except Exception as e:
         #print(e)
         print("Sorry about that I didn't hear anything say that again Please.....")
         return "None"
     return query

#It's Validate to User
def check_password():
    global i
    speak("Enter Your Password:")
    p = getpass()
    if p =="akash2600":
           speak("Access granted")
           return 1

    else:
        speak("Wrong Password!!")
        i += 1
        if i>=3:
            speak("goodbye Access Denied")
            exit()
        check_password()

#Main Function
if __name__ == '__main__':
         ch = int(check_password())
         if ch == 1:
            wishMe()
            while True:
               query = takeCommand().lower()
               print(query)

               if 'wikipedia' in query:
                 speak('Searching Wikipedia....')
                 query = query.replace("wikipediaa","")
                 results = wikipedia.summary(query,sentences=3)
                 speak("According to Wikipedia")
                 print(results)
                 speak(results)

               elif 'switch the window' in query:
                   pyautogui.keyDown("alt")
                   pyautogui.press("tab")
                   time.sleep(1)
                   pyautogui.keyUp("alt")


               elif 'open google' in query:
                    speak("sir,what should i search on google")
                    cm = takeCommand().lower()
                    webbrowser.open(f"{cm}")
                    time.sleep(5)

               elif 'open chrome' in query:
                     speak("Ok sir Opening Chrome")
                     os.system("start chrome")
                     time.sleep(5)

               elif 'open youtube' in query:
                      speak("ok sir Opening Youtube")
                      webbrowser.open("youtube.com")
                      time.sleep(5)

               elif 'open stack overflow' in query:
                    speak("PLease Wait sir Opeaning Stack Overflow")
                    webbrowser.open("stackoverflow.com")
                    time.sleep(10)

               elif 'play music' in query or 'play by choice' in query:
                    music_dir = 'D:\\MUSIC\\New folder'
                    songs = os.listdir(music_dir)
                    rd = random.choice(songs)
                    os.startfile(os.path.join(music_dir,rd))
                    time.sleep(10)

               elif 'the time' in query or 'what the time is it' in query:
                   date_time2 = datetime.datetime.now().strftime("%I:%M %p")
                   speak("Its"+date_time2)

               elif 'open code' in query:
                    codepath = "C:\\Users\\Dell\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe"
                    os.startfile(codepath)

               elif 'goodbye' in query or 'you can go now' in query:
                    speak("ok sir goodbye it's nice conservation with you")
                    exit()
               elif 'open instagram' in query:
                    speak("Ok sir, Opening Instagram")
                    webbrowser.open("www.instagram.com")

               elif 'open facebook' in query:
                    speak("Ok Opening Facebook")
                    webbrowser.open("www.facebook.com")

               elif 'open notepad' in query:
                    speak("Ok sir,Opening Notepad")
                    path3 = "C:\\Windows\\notepad.exe"
                    os.startfile(path3)
                    speak("Your notepad is opened do you want to write something in notepad")
                    t = takeCommand().lower()
                    if 'no' in t:
                         speak("Ok sir")
                    elif 'yes' in t:
                        speak("What should i write:")
               elif 'who invent you' in query:
                    speak("I'm invent by Mr Akash Khandelwal a Recent Graduate in Computer Science")


               elif 'who is akash khandelwal' in query:
                    speak("Akash khandelwal is a Computer Science Graduate Apart from that he well qualified Programmer and developer")

               elif 'i am coming' in query:
                    speak("Where are you going")
                    t = takeCommand()
                    speak("ok sir I'm waiting for you")

               elif 'i am not sleep well last night' in query:
                    speak("you spend whole night on your mobile phone You should not excessive use of your mobile phone")


               elif 'how are you' in query:
                    speak("I'm fine sir and How about you")


               elif 'wakeup alexa' in query or 'alexa' in query:
                    speak("Yes sir How may I help you")

               elif 'who are you' in query:
                    speak("I am Alexa sir your Virtual Desktop Assisstant 2.2.0")

               elif 'open cmd' in query:
                     speak("ok opening Command Prompt")
                     os.system("start cmd")
                     time.sleep(5)

               elif 'open powershell' in query:
                     speak("ok sir,Opening Window Powershell")
                     os.system("start powershell")
                     time.sleep(5)

               elif 'open camera' in query:
                    cap = cv2.VideoCapture(0)
                    while True:
                        ret,img = cap.read()
                        cv2.imshow('webcam',img)
                        k = cv2.waitKey(0)
                        if k == 27:
                           break
                        cap.release()
                        cv2.destroyAllWindows()

               elif 'ip address' in query:
                    ip = get('https://api.ipify.org').text
                    speak(f"your ip address is{ip}")

                # to close any application

               elif 'close excel' in query:
                   speak("okay sir,closing excel")
                   os.system("taskkill /f /im EXCEL.exe")

               elif 'close word' in query:
                   speak("okay sir,closing word")
                   os.system("taskkill /f /im WINWORD.exe")

               elif 'close firefox' in query:
                   speak("okay sir,closing Powershell")
                   os.system("taskkill /f /im firefox.exe")


               elif 'close rapidtyping' in query:
                   speak("okay sir,closing Powershell")
                   os.system("taskkill /f /im RapidTyping.exe")


               elif 'close powershell' in query:
                   speak("okay sir,closing Powershell")
                   os.system("taskkill /f /im powershell.exe")

               elif 'close cmd' in query:
                   speak("okay sir,closing Command Prompt")
                   os.system("taskkill /f /im cmd.exe")

               elif 'close code' in query:
                   speak("okay sir,closing Code")
                   os.system("taskkill /f /im Code.exe")

               elif 'close notepad' in query:
                    speak("okay sir,closing notepad")
                    os.system("taskkill /f /im notepad.exe")

               elif 'close chrome' in query:
                   speak("okay sir,closing chrome")
                   os.system("taskkill /f /im chrome.exe")

                # to find a joke
               elif 'tell me a joke' in query:
                    joke = pyjokes.get_joke()
                    speak(joke)
               #Some Special Command
               elif "shut down the system" in query:
                    os.system("shutdown /s /t 5")

               elif "restart the system" in query:
                    os.system("shutdown /r /t 5")

               elif "sleep the system" in query:
                   os.system("rundll32.exe powrprof.dll,SetSuspendState 0,1,0")


                # Weather API
               elif "tell me weather report" in query:
                      speak("For Which City")
                      t = takeCommand()
                      if t!='None':
                         Weather_Report(t)
               elif "open rapid typing" in query:
                     speak("Ok sir Opening Rapid Typing")
                     path5 = "C:\\Program Files (x86)\\RapidTyping 5\\RapidTyping.exe"
                     os.startfile(path5)
                     time.sleep(5)

               elif "i have mood off typing" in query:
                     speak("Can I open Rapid Typing for you")
                     t = takeCommand().lower()
                     if 'ok open' in t:
                         os.startfile(path5)
                     else:
                          pass

               elif "tell me news" in query:
                     speak("Please wait sir,Fetching latest news from times of india")
                     news()

               elif "start word" in query:
                    speak("ok sir Opening word")
                    os.startfile("C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE")
                    time.sleep(5)
               elif "open excel" in query:
                     speak("ok sir Opening Excel")
                     os.startfile("C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE")
                     time.sleep(5)

               elif "open firefox" in query:
                    speak("ok sir Opening firefox")
                    os.startfile("C:\\Program Files (x86)\\Mozilla Firefox\\firefox.exe")
                    time.sleep(5)

               elif "don't listen" in query:
                    speak("For how much time you want to stop jarvis from listening commands")
                    speak("tell me time only in seconds")
                    try:
                        a = int(takeCommand())
                        time.sleep(a)
                        print(a)
                    except Exception as e:
                         speak("tell me only time")

               elif 'write a note' in query:
                   speak("waht should i write,sir")
                   note = takeCommand()
                   file = open("jarvis.txt",'w')
                   speak("sir,Should i include date and time")
                   sdt = takeCommand().lower()
                   if 'yes' in sdt or 'sure' in sdt:
                       date_time = datetime.datetime.now().strftime("%d %b %Y | %I:%M:%S %p")
                       file.write(date_time)
                       file.write(" :-")
                       file.write(note)

                   else:
                       file.write(note)

               elif 'calculate' in query or 'calculation' in query:
                    client = wolframalpha.Client('WTXR73-743UE5RY9H')
                    speak("What type of Operation do you want do")
                    try:
                     t = str(takeCommand())
                     if t!='None':
                       res = client.query(t)
                       output = next(res.results).text
                       speak(output)
                    except Exception as e:
                         print("What did you mean")

               elif 'Take a Screenshot' in query:
                   myScreenShot = pyautogui.screenshot()
                   name = random.randint(1,9000)
                   screenshotname = str(name) + "screenshot"
                   myScreenShot.save(f"C:\\Users\\Dell\\Desktop\\Screenshot\\{screenshotname}.png")
                   speak("Screenshot taken Successfully")

               elif 'are you stupid' in query:
                   speak("I am not Stupid I think you are stupid")


