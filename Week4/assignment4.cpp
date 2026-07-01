#include <iostream>
#include <vector>
#include <string>

void removeCopies(std::vector<int>& data){
    // The vector is sorted in non-decreasing order.
    // Remove all duplicate values in-place so that
    // each value appears exactly once.
    //
    // Do not create another vector.
    // Modify the vector named "data" directly.
    //
    // Maybe two-pointer method? Hmm?
    // Hint: resize() function
    if (data.empty()) return;
    
    size_t unique_idx = 0;
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] != data[unique_idx]) {
            unique_idx++;
            data[unique_idx] = data[i];
        }
    }
    data.resize(unique_idx + 1);
}

void isAnagram(std::string officer_name, std::string spy_name){
    // Write code to see if the spy name is an anagram of the officer name 
    // Maybe a vector of size 26? Hmm?
    if (officer_name.length() != spy_name.length()) {
        std::cout << "IMPOSTER! IMPOSTER!" << std::endl;
        return;
    }
    
    std::vector<int> letter_counts(26, 0);
    for (char c : officer_name) {
        letter_counts[c - 'a']++;
    }
    for (char c : spy_name) {
        letter_counts[c - 'a']--;
    }
    
    for (int count : letter_counts) {
        if (count != 0) {
            std::cout << "IMPOSTER! IMPOSTER!" << std::endl;
            return;
        }
    }
    
    std::cout << "No imposter detected!" << std::endl;
}

int main(){
    /*Use other test cases to make sure you program works*/
    std::vector<int> server = {1,1,2,2,2,3,3,4,5,6,6,6};
    
    /*Print out the original server vector before function called*/
    for (auto data : server){
        std::cout << data << " "; // 1,1,2,2,2,3,3,4,5,6,6,6
    }
    std::cout << std::endl;

    removeCopies(server);

    /*Print out the modification of the server vector after function called*/
    for (auto data : server){
        std::cout << data << " ";
    }
    std::cout << std::endl;

    /****************************TEST ANAGRAM*************************************/
    isAnagram("syeda", "aysed"); // No imposter detected!
    isAnagram("angelo", "annabeth"); // IMPOSTER! IMPOSTER!
    return 0;
}