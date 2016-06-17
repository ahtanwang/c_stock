#-*- coding: UTF-8 -*- 
import pylab
import numpy as np
import pandas as pd    
import matplotlib.pyplot as plt
import tushare as ts
import mylib as me
import os



com1 = ' '
com2 = ' '
com3 = ' '

LW = 8

def View_10X(plt,df, d):
    size = df.index.size
    d_size = size / 10
    plt.xticks(range(0, size, d_size))
    ax=plt.gca() 
    sL = []

    if ( d == '123'):
        arr = range(0, size, d_size)
        for i in range(10):
            sL.append(str(df.iat[arr[i],0]))
        sL.append(str(df.iat[size-1,0])) 
        ax.set_xticklabels(sL, rotation = 45)

def ShowGS(com1, com2, com3):
	if com3 == 'syl30':
		f_view = "..\\..\\data\\view\\" + com2 + ".txt"
		if  os.path.exists(f_view) == False:
			print "...[Error] no file " + f_view
			return
		df = pd.read_table(f_view, sep=' +', engine = 'python')
		if df.index.size > 250:
			df1 = df.drop(range(df.index.size - 250))
		plt.title(com2 + '  ' +  com3 + '  '  + str(max(df1['date'])))
		plt.fill_between(df1.index, df1['syl30'], 0, where=df1['syl30']>0,facecolor='red')
		plt.fill_between(df1.index, df1['syl30'], 0, where=df1['syl30']<=0,facecolor='green')
	elif com3 == 'syl250':
		f_view = "..\\..\\data\\view\\" + com2 + ".txt"
		if  os.path.exists(f_view) == False:
			print "...[Error] no file " + f_view
			return
		df = pd.read_table(f_view, sep=' +', engine = 'python')
		plt.fill_between(df.index, df['syl250'], 0, where=df['syl250']>0,facecolor='red')
		plt.fill_between(df.index, df['syl250'], 0, where=df['syl250']<=0,facecolor='green')
		plt.title(com1 + '  ' +  com2 + '  '  + str(max(df['date'])))
		View_10X(plt,df, '123')
	else:
		print '[Error] input error ...'
		return
		
	plt.show()
	plt.close()

def ShowHY(com1, com2, com3):
	if com3 == 'syl30':
		f_view = "..\\..\\data\\view\\" + com2 + ".txt"
		if  os.path.exists(f_view) == False:
			print "...[Error] no file " + f_view
			return
		df = pd.read_table(f_view, sep=' +', engine = 'python')
		if df.index.size > 250:
			df = df.drop(range(df.index.size - 250))
		plt.fill_between(df.index, df['syl30'], 0, where=df['syl30']>0,facecolor='red')
		plt.fill_between(df.index, df['syl30'], 0, where=df['syl30']<=0,facecolor='green')
		plt.title(com1 + '  ' +  com2 + '  '  + str(max(df['date'])))
		
	elif com3 == 'syl250':
		f_view = "..\\..\\data\\view\\" + com2 + ".txt"
		if  os.path.exists(f_view) == False:
			print "...[Error] no file " + f_view
			return
		df = pd.read_table(f_view, sep=' +', engine = 'python')
		plt.fill_between(df.index, df['syl250'], 0, where=df['syl250']>0,facecolor='red')
		plt.fill_between(df.index, df['syl250'], 0, where=df['syl250']<=0,facecolor='green')
		plt.title(com1 + '  ' +  com2 + '  '  + str(max(df['date'])))
		View_10X(plt,df, '123')

	elif com3 == 'p120d':
		f_view = "..\\..\\data\\view\\" + com2 + ".txt"
		if  os.path.exists(f_view) == False:
			print "...[Error] no file " + f_view
			return
		df = pd.read_table(f_view, sep=' +', engine = 'python')
		plt.fill_between(df.index, df['p120d'], 0, where=df['p120d']>0,facecolor='red')
		plt.fill_between(df.index, df['p120d'], 0, where=df['p120d']<=0,facecolor='green')
		plt.title(com1 + '  ' +  com2 + '  '  + str(max(df['date'])))
		View_10X(plt,df, '123')		

	elif com3 == 'p30d':
		f_view = "..\\..\\data\\view\\" + com2 + ".txt"
		if  os.path.exists(f_view) == False:
			print "...[Error] no file " + f_view
			return
		df = pd.read_table(f_view, sep=' +', engine = 'python')
		if df.index.size > 250:
			df = df.drop(range(df.index.size - 250))
		plt.fill_between(df.index, df['p30d'], 0, where=df['p30d']>0,facecolor='red')
		plt.fill_between(df.index, df['p30d'], 0, where=df['p30d']<=0,facecolor='green')
		plt.title(com1 + '  ' +  com2 + '  '  + str(max(df['date'])))
	else:
		print '[Error] input error ...'
		return
		
	plt.show()
	plt.close()
	
	
	
def ShowMoney(com1, com2, com3):
	pass

def man():
	print '   gscode  hb/sr/syl30/syl250'
	print '   hycode gbsr/sr/p30d/p120d/syl30/syl250'
	print '   hy -- output all hy info'
	print '   m1'
	
while True:
	com1 = ' '
	com2 = ' '
	com3 = ' '
	print  '------------------------------------------------------------'
	print  'Please input command(q for exit) .......'
	line = raw_input()
	lst = line.split(' ')
	if len(lst) == 1:
		com1 = lst[0]
	elif len(lst) == 2:
		com1 = lst[0]
		com2 = lst[1]
	elif len(lst) > 2:
		com1 = lst[0]
		com2 = lst[1]
		com3 = lst[2]
	print 'Your input command is : ', com1, com2, com3		
		
	if com1 == 'q':
		break 
		

	if com1 == 'gs':
		ShowGS(com1, com2, com3)
		continue
		
	elif com1 == 'hy':
		ShowHY(com1, com2, com3)
		continue
		
	elif com1 == 'm1':
		ShowMoney(com1, com2, com3)
		continue	
		
	print '[Error] input error ...'
	man()
	
	
		

	
	
	
