#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 


/*
Description:
This algorithm is called Binary Searh in a few words is an algorithm that help us find
an element in an array (for example), but this most be already sorted, is very efficient
because it makes a bipartition of the elements and compares whether the element is in
the left half or in the right half, after that, it once again make a bipartition looking 
for the searched element.
*/

/*
Funtion Binary_Search:
Is a RECURSIVE FUNTION that returns the position of the element (if it was found).
It continue making the bipartition of the elements if it hasnt found the element.
If it wasnt found element by the time it cannot make more bipartitions it return an -1.

Parameters: 1) Need a vector of elements (they need to be already sorted).
			2) The element you want to find.
			3) Left boundary of the set.
			4) Right Boundary of the set.
*/
int Binary_Search(vector<int> &set, int element, int left_boundary, int right_boundary)
{
	//Variable needed for knowing the middle position of every set
	int middle;
	middle = (left_boundary + right_boundary) / 2;

	//This means the binary search has already done all the bipartitions, so element wasnt found, return -1
	if(left_boundary > right_boundary)
		return middle = -1;
	//This means the element was found right in the middle of the set, so return the position
	else if(element == set[middle])
		return middle;
	//If the element is greater than the middle, the left boundary need to be overwritten
	else if(element > set[middle])
		Binary_Search(set, element, middle + 1, right_boundary);
	//If the element is less than the middle, the right boundary need to be overwritten
	else if(element < set[middle])
		Binary_Search(set, element, left_boundary, middle - 1);	
}

/*
Lets make an example of how to use it
*/
int main()
{
	//Create a vector with 5 elements, and the element we want to search, and the return position
	vector<int> numbers;
	int search_this;
	int position;

	numbers.push_back(5);
	numbers.push_back(17);
	numbers.push_back(8);
	numbers.push_back(11);
	numbers.push_back(1);

	//We nees to sort the array first
	sort(numbers.begin(), numbers.end());

	for(int i = 0; i < numbers.size(); i++)
		cout << "Position " << i+1 << ": " << "Element: " << numbers[i] << endl;

	char another_search;

	while(another_search != 'n')
	{
		cout << "Which element of the current vector you want to search: ";
		cin >> search_this;

		position = Binary_Search(numbers, search_this, 0, numbers.size() - 1);

		if(position == - 1)
			cout << "The element: " << search_this << " wasnt found in the vector" << endl;
		else
			cout << "The element: " << search_this << " was found in the position " << position + 1 <<endl;

		cout << "\nYou want another searh? Press n if not ";
		cin >> another_search;  
	}
	
	
	return 0;
}
