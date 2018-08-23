/** creates a random vector and sorts it by insertionsort. */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

/** 
 * Part of insertion sort
 *
 *  PRECONDITION: 
 *      entries v[0]..v[n-1] are in decreasing order and 
 *    	n is less than the size of v
 *  ACTION: 
 *      This function "inserts" the value v[n] into the list, 
 *      swapping some of the entries as required so that 
 *      v[0]..v[n-1],v[n] are  in decreasing order. 
 *  POSTCONDITION: 
 *      the entries v[0]..v[n] are the same values as they
 *      were orginally but possibly in a different order
 *  RETURN VALUE: 
 *      the number of comparisons (<, <= , > or >=) that were 
 *      performed on double values from v[]
 *
 * For example if v[] contains 23 13 10 4 2 1 12 17 2 then after 
 * doOneInsertion(v,6), v[] contains 23 13 12 10 4 2 1 17 2 and 
 * 5 comparisons were needed, so 5 is returned.
 */
int doOneInsertion(vector<double>& v, int n) {
    // over to you...
    int count = 0;
    for(int i=n; i>0; i--) {
        count+=1;
        if(v[i]>=v[i-1]){
            double temp = v[i];
            v[i] = v[i-1];
            v[i-1] = temp;
        } else {
        	break;
		}
    }
    return count;
 }  

/** 
 * Sorts an arbitrary vector vec by insertion sort, 
 * repeatedly using doOneInsertion(...)
 *
 * Returns the total number of comparisons that were made. 
 */
int insertionsort(vector<double>& vec) {  
    // over to you...
    int count = 0;
    for(int i=1; i<vec.size(); i++){
        count += doOneInsertion(vec,i);
    }
    return count;
}
/** 
 * Part of shell sort
 * 
 * A subvector of a vector v with entries v[0],v[1],...,v[s-1]
 * is a sequence of entries v[i],v[i+h],v[i+2*h],...,v[i+k*h]
 * (where s is the size of the original vector, 0<=i<h and i+k*h<s).  
 * So a subvector is like a subsequence (RAC:) that is specified by
 *   h>0,    the gap
 *   0<=i<h, the start point
 * The following function is exactly like "doOneInsertion" in
 * insertionsort except that it only works on the
 * the subvector  v[i],v[i+h],v[i+2*h],...,v[i+k*h]
 * where n = i+k*h.  (If you need it, the value i can be
 * calculated from n and h.)
 *
 *  PRECONDITION: 
 *      entries v[i],v[i+h],v[i+2*h],...,v[i+(k-1)*h] are in decreasing 
 *      order, n == i+k*h is less than the size of v, i as above
 *  ACTION: 
 *      This function "inserts" the value v[n] into the above list, 
 *      swapping some of the entries as required so that 
 *      v[i],v[i+h],v[i+2*h],...,v[i+k*h] are in decreasing order. 
 *  POSTCONDITION: 
 *      the entries v[i],v[i+h],v[i+2*h],...,v[i+k*h] are the same 
 *      values as they were orginally, but possibly in a different order.
 *  RETURN VALUE: 
 *      the number of comparisons (<, <=, >= or >) that were made 
 *      on double values from v[]
 *
 * For example if v[] contains 23 3 13 4 10 7 12 17 2 then after 
 * doOneInsertion(v,6,2), v[] contains 23 3 13 4 12 7 10 17 2 and 
 * 2 comparisons were needed, so 2 is returned.
 */
int doOneInsertion2(vector<double>& v, int n, int h) {
	// over to you...
    int count = 0;
    if(n<h){return 0;}
    for(int index=n; index>n%h; index-=h){
        count+=1;
        if(v[index]>=v[index-h]){
            double temp = v[index];
            v[index] = v[index-h];
            v[index-h] = temp;
        } else {
        	break;
		}
    }
    return count;
}

int shellsort(vector<double>& vec) {
	// over to you...
	const vector<int> gaps = {701, 301, 132, 57, 23, 10, 4, 1};
    int count=0;
    for(int i=0; i<gaps.size(); i++){
    	for(int j=1; j<vec.size(); j++) {
        	count += doOneInsertion2(vec,j,gaps[i]);
    	}
    }
    return count;
}

/* Print a vector to standard output, cout. */
void printVector(vector<double>& data) {  
  int nentries = data.size();
  for (int n = 0 ; n<nentries ; n++) {
    cout << data[n] << " ";
  }
  cout << endl;
}

/* Returns true if vec is sorted in nonincreasing order, false
   otherwise, and prints a message to cout. */
bool testSorted(vector<double>& vec) {
  int s = vec.size();
  for (int i=1; i<s; i++) {
    if (vec[i-1] < vec[i]) {
      cout << "Data is not sorted" << endl;
      return false;
    }
  }
  cout << "Data is sorted" << endl;
  return true;  
}

/* A version of bubblesort that returns the number of comparisons made. */
int bubblesort(vector<double>& vec) {
  int count = 0;
  int s = vec.size();
  for (int i=0; i<s; i++) {
    for (int j=i+1; j<s; j++) {
      count++; // There's a comparison coming up!
      if (vec[i] < vec[j]) {
    double x = vec[i];
    vec[i] = vec[j];
    vec[j] = x;
      }
    }
  }
  return count;
}

/* fills the vector "data" with nentries chosen
 * "randomly" from 0..1 */
void fillVector(vector<double>& data, int nentries) {
  data.clear();
  for (int n = 0 ; n<nentries ; n++) {
    double p = double(rand())/RAND_MAX; 
    // you may prefer to replace the above line with
    //   cin >> p;
    // so that you can enter your own data from the keyboard.
    // or put this version as a new function to be called from main.
    data.push_back(p);
  }	
}

/* fills the vector "data" with nentries chosen
   "in a partially sorted way" from 0..1 */
void fillVectorPS(vector<double>& data, int nentries) {
  data.clear();
  /* create data in "blocks".  Block n=k contains
     values from k/10 to (k+1)/10  Blocks count
     downwards. */
  int k = 10; // number of block we are in
  int nblocks = 10; // number of blocks
  int n = 0; // index of next item;
  double blocksize = 1.0/k; 
  while(n<nentries) {
    double p = double(rand())/RAND_MAX; // from 0 to 1
    p = p*blocksize + k*blocksize;
    data.push_back(p);
    n++;
    if (n%nblocks == 0) k--;
  }	
}

/* A "main" for you to tinker with to help you get started in 
 * testing your functions. This will not be assessed, but
 * thorough testing is still your responsibility.
 * un-commentout the lines with // as you wish... 
 */
int main () {
  int count = 0;
  vector<double> data1;
  vector<double> data2;
  vector<double> data3;
  int nentries; 
  cout << "Number of entries? " << endl;
  cin >> nentries;

  /* initialize random seed: */
  srand(time(NULL));
  // OR
  // srand(102938); // change this number if needed

  fillVector(data1, nentries);
  // vectors can be copied in C++ using = like any other variables
  data2 = data1;
  data3 = data1;
/*
  vector<double> data4 = {23,3,13,4,10,7,12,17,2};
  printVector(data4);
  shellsort(data4);
  //doOneInsertion2(data4,7,3);
  printVector(data4);
*/



  testSorted(data1); // check if the vector is already sorted
  cout << "Sorting.." << endl;
  
  cout << "Using bubblesort..." << endl;
  count = bubblesort(data1);
  testSorted(data1);
  cout << "bubblesort complete with " << count << " comparisons" << endl;

  cout << "Using insertionsort..." << endl;
  count = insertionsort(data2);
  //printVector(data2);
  testSorted(data2);
  cout << "insertionsort complete with " << count << " comparisons" << endl;

  cout << "Using shellsort..." << endl;
  count = shellsort(data3);
  //printVector(data3);
  testSorted(data3);
  cout << "shellsort complete with " << count << " comparisons" << endl;

  return 0;
}
