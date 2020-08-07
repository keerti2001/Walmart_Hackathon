# -*- coding: utf-8 -*-
"""
Created on Fri Aug  7 15:20:06 2020

@author: KEERTI
"""
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


train=pd.read_csv(r'dataset.csv')
base=train.iloc[:,1:3]
p1=train.iloc[:,3:5]
p2=train.iloc[:,5:7]
p3=train.iloc[:,7:9]
p4=train.iloc[:,9:11]



base_rev=[]
for i in range(300):
    base_rev.append(base['Base_Price'][i]*base['Base_Units'][i])

r1=[]
h1=[]
for i in range(300):
    r1.append(p1['Price1'][i]*p1['Units1'][i])
    h1.append((base['Base_Price'][i]-p1['Price1'][i])*p1['Units1'][i])
    
r2=[]
h2=[]
for i in range(300):
    r2.append(p2['Price2'][i]*p2['Units2'][i])
    h2.append((base['Base_Price'][i]-p2['Price2'][i])*p2['Units2'][i])
    

r3=[]
h3=[]
for i in range(300):
    r3.append(p3['Price3'][i]*p3['Units3'][i])
    h3.append((base['Base_Price'][i]-p3['Price3'][i])*p3['Units3'][i])
    

r4=[]
h4=[]
for i in range(300):
    r4.append(p4['Price4'][i]*p4['Units4'][i])
    h4.append((base['Base_Price'][i]-p4['Price4'][i])*p4['Units4'][i])
    
final=[]
ind=[]

for i  in range(300):
    l=[base_rev[i],r1[i],r2[i],r3[i],r4[i]]
    final.append(max(l))
    ind.append(l.index(max(l)))

q=[]
hit=[]
for i in range(300):
    if ind[i]==0:
        q.append(base['Base_Units'][i])
        hit.append(0)
    if ind[i]==1:
        q.append(p1['Units1'][i])
        hit.append(h1[i])
    if ind[i]==2:
        q.append(p2['Units2'][i])
        hit.append(h2[i])
    if ind[i]==3:
        q.append(p3['Units3'][i])
        hit.append(h3[i])
    if ind[i]==4:
        q.append(p4['Units4'][i])
        hit.append(h4[i])
    

total_base_rev=sum(base_rev)
total_base_q=sum(base['Base_Units'])

total_rev=sum(final)
total_q=sum(q)

x=(total_rev/total_base_rev-1)*100
y=(total_q/total_base_q-1)*100

total_hit=sum(hit)

