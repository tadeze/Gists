from bs4 import BeautifulSoup,SoupStrainer
import urllib2
import re
import requests
import datetime
from sqlalchemy import create_engine
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column, Integer, String, DateTime, Float, Boolean
from sqlalchemy.orm import sessionmaker


engine = create_engine('sqlite:///bbcgossip.db',echo=False)
Base = declarative_base()
class Gossip(Base):

    """
    A table to store the gossips
   # """
    __tablename__ ='gossips'
    id = Column(Integer,primary_key=True)
    created=Column(String)
    article=Column(String)
    link = Column(String,unique=True)
Base.metadata.create_all(engine)
Session = sessionmaker(bind=engine)
session = Session()




url ='http://www.bbc.com/sport/football/gossip'
def scrap_it():
    r = requests.get(url)
    soup = BeautifulSoup(r.text)
    published_date = soup.find_all('meta',property='rnews:datePublished')[0]['content']
    gossips = soup.find_all("div",class_='story-body')
    pars= gossips[0].find_all("p")
    all_gossip=[]
    page = 0
    for par in pars:
        #page = page +1
        result =[]
         #all_gossips[]
        result = [published_date,par.get_text(),None if par.a is None else par.a['href']]
        all_gossip.append(result)
         # Create the gossip object
        gossip = Gossip(link = result[2],
                 article = result[1],
                 created = result[0])

        session.add(gossip)
        session.commit()
        all_gossip.append(result)
    return all_gossip

#import pandas as pd

#df = pd.DataFrame(all_gossip,columns=["created","article","link"])
#print scrap_it()


