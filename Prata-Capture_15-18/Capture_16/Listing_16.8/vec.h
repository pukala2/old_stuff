#pragma once
#include <iostream>
#include <string>
struct Review{
    std::string title;
    int rating;
};

bool FillReview(Review & rr);
void ShowReview(const Review & rr);

