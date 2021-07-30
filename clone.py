from os import write
import subprocess
import string
for i in range(34400) :
    sbd = 29000001 + i
    cmd = "https://dantri.com.vn/thpt/3/0/99/"+ str(sbd) +"/2021/0.25/search-gradle.htm"
    res = subprocess.check_output(["curl", cmd])
    res = str(res)
    filetho = open('a.txt', 'a')
    filetho.write(res+'\n')
    filetho.close()