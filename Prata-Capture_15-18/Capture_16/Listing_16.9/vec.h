#pragma once
#include <iostream>
#include <string>
struct Review{
    std::string title;
    int rating;
};

bool FillReview(Review & rr);
void ShowReview(const Review & rr);
bool operator<(const Review & r1, const Review & r2);
bool WorseThan(const Review & r1, const Review & r2);

