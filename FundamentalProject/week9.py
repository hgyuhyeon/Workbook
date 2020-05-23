# 오픈소스기초프로젝트 9주차 퀴즈
# 제작 - 황규현
# 문제: 거북이가 랜덤으로 움직인 값과 선 색을 데이터베이스에 저장한 후 불러오기하여 왔던 길을 

import pymysql
from tkinter import *
import turtle as t
import random
from time import sleep

## 변수 선언 부분 ##
t.shape('turtle')
t.pensize(5)
t.speed(10)
t.colormode(255)
global ID
ID = 1

# 데이터베이스 연결
con = pymysql.connect(host='127.0.0.1', user='user', password='123456**', db='linedata', charset='utf8')

# 커서 생성 및 데이터베이스 드랍, 재생성
curs = con.cursor()
curs.execute("DROP table IF EXISTS turtleline")
curs.execute("CREATE table turtleline (time int, lineID int, colorR int, colorG int, colorB int, num int, x int, y int) ENGINE=InnoDB;")


## 함수 선언 부분 ##
def moveTurtle(time, ID):
    # 거북이 움직이기
    num = 1
    t.pendown()
    for i in range(0, 3, 1):
        time += 1
        r = random.randint(0, 255)
        g = random.randint(0, 255)
        b = random.randint(0, 255)
        x = random.randint(0, 300)
        y = random.randint(0, 300)
        t.pencolor(r, g, b)
        t.goto(x, y)
        num = num + 1
        sql = "INSERT INTO turtleline (time, lineID, colorR, colorG, colorB, num, x, y) VALUES(%s,%s,%s,%s,%s,%s,%s,%s)"
        value = (str(time), str(ID), str(r), str(g), str(b), str(num), str(x), str(y))
        curs.execute(sql, value)
        con.commit()
    t.penup()


def SelectData():
    # 데이터베이스에 입력된 데이터 전체 조회
    sql = "SELECT * FROM turtleline"
    curs.execute(sql)
    while (True):
        # 4. 데이터 가져오기
        row = curs.fetchone()
        if row == None :
            break;
        print(row)

def GetRecentData():
    # 최근 행 데이터 가져오기
    sql = "SELECT * FROM turtleline ORDER BY time DESC limit 1";
    curs.execute(sql)
    tup = curs.fetchall()  # 튜플형인 데이터 가져오기
    templ = list(tup)  # 튜플을 리스트형으로 변환
    string = " ".join(str(templ))  # 리스트를 /로 구분지어 문자열로 변환
    l = string.split(",")  # 문자열을 다시 열이 구분된 리스트로 변환

    for j in range(2, 8, 1):
        l[j] = re.sub('[]([)]', '', l[j])  # 리스트 값의 각종 특수기호들을 제거

    return l


def ReverseTurtle():
    # 거북이 반대로 움직이기
    t.pendown()
    for i in range(0, 6, 1):

        # RGB 데이터 겟. 가장 마지막으로 입력된 데이터부터 얻는다
        l = GetRecentData()

        # 리스트 내의 공백을 제거하여 int형으로 형변환
        r = int(l[2].replace(" ", ""))
        g = int(l[3].replace(" ", ""))
        b = int(l[4].replace(" ", ""))

        # 거북이의 이동 데이터를 얻기 위한 최근 행 1개 삭제
        sql = "DELETE FROM turtleline ORDER BY time DESC limit 1";
        curs.execute(sql)

        if(i == 5):
            x = 0
            y = 0
        else:
            # xy 데이터 겟. 마지막에서 두 번째로 입력된 데이터부터 얻는다
            l = GetRecentData()
            # 리스트 내의 공백을 제거하여 int형으로 형변환
            x = int(l[6].replace(" ", ""))
            y = int(l[7].replace(" ", ""))

        #거북이 색깔 바꾸어서
        t.pencolor(r, g, b)
        t.goto(x, y)

    t.penup()


## 메인 코드 부분 ##

time = 0
for ID in range(1, 3, 1) :
    moveTurtle(time, ID)
    time += 3
    ID += 1

SelectData()

sleep(2)
t.clear()
ReverseTurtle()
t.done()

# DB 연결 끊기
con.close()
