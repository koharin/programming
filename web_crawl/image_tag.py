#!/usr/bin/python 
#result: tag.txt
from selenium import webdriver
from bs4 import BeautifulSoup

def getUrl(t):
    driver = webdriver.Chrome('/home/koharin/chromedriver')
    driver.get(t + '?tab=tags')
    html = driver.page_source
    soup = BeautifulSoup(html, 'html.parser')

    with open('tag.txt', 'a') as f2:
        for element in soup.find_all('input', 'styles__tagPullInput___11UTk'):
            f2.write(element.get('value').split(" ")[2]+'\n')
        f2.close()
    driver.quit()

with open('image2.txt', 'r') as f:
    for i in f:
        getUrl(i.strip('\n'))
    f.close()
