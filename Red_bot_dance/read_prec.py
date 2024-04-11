from grabscreen import grab_screen
import cv2
import numpy as np
import time
import pandas as pd
from math import floor
import random

'''
expermintly found using the grabe_screen file
just find a key that is played and then subtract how far over it should be
x=num from function
x-223(n-1)

'''
#223 px between numbers
#A flat -3
#A 12
#B flat 29
#B 49
#C 75
#D flat 94
#D 110
#E flat 125
#E 145
#F 170
#G flat 188
#G 205


def read_prec(file_name,ms):
    use_list=[]
    ofset_dict={"A":12,"A_flat":-3,"B":39,"B_flat":29,"C":75,"D":110,"D_flat":94,"E":145,"E_flat":125,"F":170,"G":205,"G_flat":188}
    list_of_notes=["A","A_flat","B","B_flat","C","D","D_flat","E","E_flat","F","G","G_flat"]
    use_notes=[]
    # creat list of all notes with what should be correct values
    for i in range(6):
        for j in range(len(list_of_notes)):
            use_notes.append([list_of_notes[j]+str(i+1),i*223+ofset_dict[list_of_notes[j]]])
    '''
    for i in use_notes:
        print(i)
    '''
    #use_notes.sort(reverse =True) # this is for cordes just play the highes note always but sorting is hard and I am lazy

    # read in data
    rec=np.loadtxt(file_name)

    last_note="0"
    # track how many frames a note is playing for to get how many ms it should be played for
    frame_num=0
    for frame in rec:
        for i in use_notes:
            if frame[i[1]]!=0:
                note=i[0]
                #print(note,last_note)
            elif all(ele==0 for ele in frame): # fancy way to check if all values are zero meaning nothing is being played so append 0
                #pass
                note="0"
             
        if note!=last_note: # check when the note changes so we know to add it and how many frames it was played for
            #print(note)
            use_list.append([note,floor(frame_num*ms),random.randrange(0,2)])
            last_note=note
            frame_num=0 # reset frame count
        else:
            frame_num+=1 #incrment frame count

    for k in range(len(use_list)): # the ms values are for the note before them since they are appended at the same time so you have to swap them out so they correct. Last note is lost due to this
        if k+1>=len(use_list):
            break
        use_list[k][1]=use_list[k+1][1]
        #use_list[k][1]=str(use_list[k+1][1]).replace("[","}")
        #use_list[k][1].replace("]","},")
        
        #print(use_list[k])
        
        copy=pd.DataFrame([use_list])
        copy.to_clipboard(index=False,header=False) # copy to clipboard for easier transfer
        
    return use_list 


if __name__=="__main__":
    a=read_prec("meg_duet_g",39.54337635458068) # 

    for i in a:
        print(i) # easyier to change to correct synax if copied from here 



'''
to change the sysnax in house you could write to a file as a string, and then replace what needs to change. not sure if it would keep the [] but ctrl+h on a google doc lets you replace everything
in any way you want so if you change something works better I have found.
'''





        
