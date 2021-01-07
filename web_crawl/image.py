#!/usr/bin/python 
# result: image.txt
from selenium import webdriver
from bs4 import BeautifulSoup

for i in range(1,8):
    driver = webdriver.Chrome('/home/koharin/chromedriver')
    driver.get('https://hub.docker.com/search?q=&type=image&image_filter=official&operating_system=linux&page='+str(i))
    html = driver.page_source
    soup = BeautifulSoup(html, 'html.parser')
    with open('image.txt', 'a') as f1:
        for p in soup.find_all('a', 'imageSearchResult styles__searchResult___EBKah styles__clickable___2bfia'):
            f1.write(p.get('href')+'\n')
        f1.close()
    driver.quit()
