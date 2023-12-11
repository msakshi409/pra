def main():
    while True:
        print("1.selection sort")
        print("2.bubble sort")
        print("3.end")
        choice=int(input("enter your choice"))
        if (choice==1):
            selection_sort()
        elif(choice==2):
            bubble_sort()
        elif(choice==3):
            break
def selection_sort():
    n=int(input("enter no of students"))
    per=[]
    for i in range(n):
        x=int(input("enter percentage of students"))
        per.append(x)
    print("entered percentages are",per)
    for i in range(n):
        min_index=i
        for j in range(i+1,n):
            if (per[j]<per[min_index]):
                min_index=j
        if(min_index!=i):
            per[i],per[min_index]=per[min_index],per[i]
    print("sorted percentages are",per)
def bubble_sort():
    n=int(input("enter the no of students"))
    per=[]
    for i in range(n):
        x=int(input("enter the percentage"))
        per.append(x)
    print("entered percentages are",per)
    for i in range(n):
        swapped=0
        for j in range(n-i-1):
            if(per[j]>per[j+1]):
                per[j],per[j+1]=per[j+1],per[j]
                swapped=1
        if(swapped==0):
                break
    print("sorted percentages are",per)
    print("Top 5 scores are")
    for i in range (5):
        print(per[n-i-1])
main()


matrix operation
def main():
    a=[]
    b=[]
    r=int(input("enter the number of rows "))
    c=int(input("enter the number of column"))
    print("enter the vlueu of 1st matrix:")
    get_data(a,r,c)
    print("enter the value of second matrix:")
    get_data(b,r,c)
    print("display the first matrix:")
    dis_matrix(a,r,c)
    print("display 2nd matrix is:")
    dis_matrix(b,r,c)
    print("additioin of two matrix is:")
    add_matrix(a,b,r,c)
    print("subtraction of two matrix:")
    sub_matrix(a,b,r,c)
    print("transpose of 1st matrix is")
    trp(a,r,c)
    print("transpose of 2nd matrix:")
    trp(b,r,c)

def get_data(x,r,c):
    for i in range(r):
        a=[]
        for j in range(c):
            p=int(input("enter the value"))
            a.append(p)

        x.append(a)

def dis_matrix(x,r,c):
    for i in range(r):
        for j in range(c):
            print(x[i][j],end=" ")
        print()

def add_matrix(x,y,r,c):
    ad=[]
    for i in range(r):
        a=[]
        for j in range(c):
            p=x[i][j]+y[i][j]
            a.append(p)
        ad.append(a)
    dis_matrix(ad,r,c)
def sub_matrix(x,y,r,c):
    ad=[]
    for i in range(r):
        a=[]
        for j in range(c):
             p=x[i][j]-y[i][j]
             a.append(p)
        ad.append(a)

    dis_matrix(ad,r,c)



def trp(x,r,c):
    ad=[]
    for i in range(r):
        a=[]
        for j in range(c):
            p=x[j][i]
            a.append(p)
        ad.append(a)
    dis_matrix(ad,r,c)

main()