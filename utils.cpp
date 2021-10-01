//
// Created by Ikroop Singh Kalsi on 12-09-2021.
//
#ifndef UTILS_CPP_INCLUDED
#define UTILS_CPP_INCLUDED

#include <iostream>
#include <vector>

struct Utils {
    template <typename T>
    static std::vector<T> getNewVector(std::initializer_list<T> list){
        return std::vector<T>(list);
    }

    template<typename T>
    static std::vector<std::vector<T>> getNewGrid(std::vector<std::vector<T>> grid) {
        return std::vector<std::vector<T>>(grid);
    }

    template <typename T>
    static void printVector(std::vector<T> v) {
        for (auto item: v) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    template <typename T>
    static void printGrid(std::vector<std::vector<T>> g) {
        for (auto row: g) {
            for (auto item: row) {
                std::cout << item << " ";
            }
            std::cout << "\n";
        }
        std::cout << std::endl;
    }

    template <typename T>
    static void print(T something) {
        std::cout << something << std::endl;
    }
};

#endif
