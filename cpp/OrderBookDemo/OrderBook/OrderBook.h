//
// Created by tadeze on 4/22/16.
// Based on screen cast by Dmitri Nesteruk
//
#pragma once
#include<iostream>
#include <map>
#include<boost/optional.hpp>
class OrderBook {
    std::map<int,int> bids,asks;
    void add(int price,int amount, bool bid);
    void remove(int price,int amount, bool bid);
public:
    struct BidAsk {
        typedef boost::optional<std::pair<int,int> > Entry;
        Entry bid,ask;
        boost::optional<int> spread() const;
    };

    inline bool is_empty() const{
        return bids.empty() && asks.empty();
    }
    void add_bid(int price, int amount);
    void add_ask(int price, int amount);
    void remove_bid(int price, int amount);
    void remove_ask(int price, int amount);
   friend  std::ostream & operator<<(std::ostream& os, const OrderBook& book);
   friend  std::ostream & operator<<(std::ostream& os, const OrderBook::BidAsk& ba);

    BidAsk get_bid_ask() const;
};

