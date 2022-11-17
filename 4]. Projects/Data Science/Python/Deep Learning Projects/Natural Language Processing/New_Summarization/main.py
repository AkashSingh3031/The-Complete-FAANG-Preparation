import tkinter as tk
import nltk
from textblob import TextBlob
from newspaper import Article
import pyttsx3  
nltk.download('punkt')

def summarize():

    url =utext.get('1.0', "end").strip()               

    article =Article(url)

    article.download()
    article.parse()
 
    article.nlp()

    title.config(state='normal')
    summary.config(state='normal')
    sentiment.config(state='normal')

    title.delete('1.0', 'end')
    title.insert('1.0', article.title)

    summary.delete('1.0', 'end')
    summary.insert('1.0', article.summary)

    analysis = TextBlob(article.text)
    sentiment.delete('1.0','end')
    sentiment.insert('1.0',f'Polarity:{analysis.polarity}, Sentiment: {"postive" if analysis.polarity > 0    else "negative" if analysis.polarity < 0 else " neutral"}')

    title.config(state='disabled')
    summary.config(state='disabled')
    sentiment.config(state='disabled')

    summary.delete('1.0', 'end')
    summary.insert('1.0', article.summary)

    print(f'Title:{article.title}')
    print(f'Authors:{article.authors}')
    print(f'Publish Date:{article.publish_date}')
    print(f'Summary:{article.summary}')
    
def audio_summary():
    url =utext.get('1.0', "end").strip()               

    article =Article(url)

    article.download()
    article.parse()
 
    article.nlp()
    mytext=article.summary
    engine = pyttsx3.init()
    engine.say(mytext)
    engine.runAndWait()

root=tk.Tk()
root.title("News Summarize")
root.geometry('600x600')

ulabel = tk.Label(root, text="URL")
ulabel.pack()

utext =tk.Text(root, height=1, width=70)
utext.pack()

tlable=tk.Label(root,text="Title")
tlable.pack()


title=tk.Text(root, height=1, width=70)
title.config(state='disabled',bg='#dddddd')
title.pack()

slable=tk.Label(root,text="Summarize")
slable.pack()
summary=tk.Text(root, height=20, width=70)
summary.config(state='disabled',bg='#dddddd')
summary.pack()

selabel =tk.Label(root, text="Sentiment Analysis")
selabel.pack()

sentiment =tk.Text(root, height=1, width=70)
sentiment.config(state='disabled',bg='#dddddd')
sentiment.pack()

btn =tk.Button(root,text="Summarize",command=summarize)
btn.pack()
btn =tk.Button(root,text="Audio",command=audio_summary)
btn.pack()


root.mainloop()
