// macro
#pragma once

#ifndef BASE_H
#define BASE_H

// golbal parameter
extern int gcount;

// function
int TestFunc(int, int x, int y = 10);

// C-function
extern "C" void TestC();

extern "C" {
  void TestC1();
  void TestC2();
}

#endif
