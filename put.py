import tkinter
from tkinter import ttk

'''
ボタンをクリックすることで以下を選択できるようにする

◇◇◇要件◇◇◇
・自分の駒
        色：白
        形状：〇
・PCの駒
        色：黒
        形状：〇
・駒が置かれていない場所
        色：緑色
        形状：四角

'''

import tkinter

def fnc_do_1(event):
    pass

# 画面作成
window = tkinter.Tk()
window.geometry("1000x1000")
window.title("オセロ")

# ボタン作成
btn = tkinter.Button(window,bg="green",text="駒")

# ボタン表示
btn.place(x=125, y=230, width=150, height=150)

# ボタンに関数をbind
btn.bind("<Button-1>", fnc_do_1)

# 画面表示（常駐）
window.mainloop()