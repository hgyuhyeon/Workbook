#다른 데이터베이스 사용
#탄수화물, 단백질, 지방 표기 추가, 그 외 시스템은 거의 동일
#DB 인서트 과정에서 예외가 발생하여 일부 음식의 칼로리 표시가 정상적으로 되어있지 않음
from tkinter import *
import pymysql

def isfull(kcal): # 칼로리가 전부 찼는가?
    if(kcal>300):
        return True
    else:
        return False

def getdata():
    sql = "SELECT * FROM nutrient ORDER BY RAND() LIMIT 1"
    curs.execute(sql)
    data = curs.fetchall()

    return data

def gettime():
    while (1):
        command = input("원하는 식단(아침, 점심, 저녁): ")

        if (command == "아침"):
            return "아침"
        elif (command == "점심"):
            return "점심"
        elif (command == "저녁"):
            return "저녁"
        else:
            print("잘못된 입력")


def convertdata(data):
    tup = getdata()  # 튜플형인 데이터 가져오기
    templ = list(tup)  # 튜플을 리스트형으로 변환
    string = " ".join(str(templ))  # 리스트를 /로 구분지어 문자열로 변환
    l = string.split(",")  # 문자열을 다시 열이 구분된 리스트로 변환

    for j in range(0, 12, 1):
        l[j] = re.sub(r'[][''\()[]', '', l[j])  # 리스트 값의 각종 특수기호들을 제거

    return l


class daily:
    def __init__(self):
        self.namelist = []


    def makedata(self):

        kcal = 0
        protein = 0
        fat = 0
        carbohydrate = 0

        catelist = []
        while(kcal <= 300):
            data = getdata()  # 데이터를 얻고
            l = convertdata(data)  # 그 데이터를 리스트로 변환하여

            if str(l[0]).replace(" ", "") in catelist:
                continue #같은 카테의 데이터가 있으면 continue(거름)

            catelist.append(str(l[3].replace(" ","")))
            namelist.append(str(l[0].replace(" ", "")))  # 식단표 안에 음식이름 추가
            kcal += float(l[8].replace(" ", ""))
            protein += float(l[9].replace(" ", ""))
            fat += float(l[10].replace(" ", ""))
            carbohydrate += float(l[11].replace(" ", ""))

            if(isfull(kcal)==True):
                namelist.append(kcal)
                namelist.append(protein)
                namelist.append(fat)
                namelist.append(carbohydrate)
                break

        return namelist

    def makelist(self):
        print("\n\n오늘의 랜덤식단!")
        daily.printonedaydata(self)
        #print(kcal)

    def printonedada(time):
        print(time)
        one = daily.makedata(self=kcal)
        print(one)
        del one[:]

    def printonedaydata(self):
        for i in range(0, 3, 1):
            if (i==0):
                print("아침")
            elif (i==1):
                print("점심")
            else:
                print("저녁")
            once = daily.makedata(kcal)
            print(once)
            # print(kcal)
            del once[:]


class weekly:
    def makelist(self):
        daylist = ["월요일", "화요일", "수요일", "목요일", "금요일", "토요일", "일요일"]
        print("\n\n이번 주 랜덤식단!")
        for i in range(0, 7, 1):
            print("\n"+daylist[i])
            daily.printonedaydata(self)

class monthly:
    def makelist(self):
        daylist = ["월요일", "화요일", "수요일", "목요일", "금요일", "토요일", "일요일"]
        print("\n\n이번 달 랜덤식단!")
        for i in range(1, 5, 1):
            print("\n\n"+str(i)+"주차")
            for j in range(0, 7, 1):
                print("\n"+daylist[j])
                daily.printonedaydata(self)

if __name__ == "__main__":
    ##connect to server##
    con = pymysql.connect(host='localhost', user='user',
                           password='123456**', db='foods', charset='utf8')
    curs = con.cursor()

    while(1):
        command = input("얻을 데이터(개별, 일일, 주간, 월간, 입력값 없을 시 종료): ")
        ##변수 선언##
        namelist = []  # 식단표 리스트
        kcal = 0

        if (command == "개별"):
            time = gettime()
            daily.printonedada(time)
        elif(command == "일일"):
            daily.makelist("")
        elif(command == "주간"):
            weekly.makelist("")
        elif(command == "월간"):
           monthly.makelist("")
        elif(command == ""):
            break
        else:
            print("잘못된 입력")


    con.close()
