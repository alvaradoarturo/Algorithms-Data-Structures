/* Since we are looking for two values that will sum to equal something, my intial idea is to create two for loops. These two
loops will evaluate all possible pairings. Since we are nesting these for loops, we know we have a runtime of O(N^2). */

int countCubeSumPairs(int n) {
    int numPairs = 0;
    for(int i = 1; i < 1000; i++){
		  for(int j = 0; j < 1000; j++){
			  if(pow(i,3) + pow(j,3) == n){
                numPairs++;
        }
      }  
    }
    return numPairs;
}
