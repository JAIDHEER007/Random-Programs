#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int ctoi(char ch){
	return ch - '0'; 
}

vector<vector<int>> getAdjMat(string keypad){
	vector<int> row(10, 0);
	vector<vector<int>> matrix(10, row);
	
	//Corner Pieces: 0, 2, 6, 8
	
	// 0 -> 1
	// 0 -> 3
	// 0 -> 4
	matrix[ctoi(keypad[0])][ctoi(keypad[1])] = 1;
	matrix[ctoi(keypad[0])][ctoi(keypad[3])] = 1;
	matrix[ctoi(keypad[0])][ctoi(keypad[4])] = 1;
	
	// 2 -> 1
	// 2 -> 5
	// 2 -> 4
	matrix[ctoi(keypad[2])][ctoi(keypad[1])] = 1;
	matrix[ctoi(keypad[2])][ctoi(keypad[5])] = 1;
	matrix[ctoi(keypad[2])][ctoi(keypad[4])] = 1;
	
	// 6 -> 3
	// 6 -> 4
	// 6 -> 7
	matrix[ctoi(keypad[6])][ctoi(keypad[3])] = 1;
	matrix[ctoi(keypad[6])][ctoi(keypad[4])] = 1;
	matrix[ctoi(keypad[6])][ctoi(keypad[7])] = 1;
	
	// 8 -> 5
	// 8 -> 4
	// 8 -> 7
	matrix[ctoi(keypad[8])][ctoi(keypad[5])] = 1;
	matrix[ctoi(keypad[8])][ctoi(keypad[4])] = 1;
	matrix[ctoi(keypad[8])][ctoi(keypad[7])] = 1;
	
	//Diamond Pieces: 1, 3, 5, 7
	
	// 1 -> 0
	// 1 -> 2
	// 1 -> 3
	// 1 -> 5
	// 1 -> 4
	matrix[ctoi(keypad[1])][ctoi(keypad[0])] = 1;
	matrix[ctoi(keypad[1])][ctoi(keypad[2])] = 1;
	matrix[ctoi(keypad[1])][ctoi(keypad[3])] = 1;
	matrix[ctoi(keypad[1])][ctoi(keypad[5])] = 1;
	matrix[ctoi(keypad[1])][ctoi(keypad[4])] = 1;
	
	// 3 -> 0
	// 3 -> 6
	// 3 -> 1
	// 3 -> 7
	// 3 -> 4
	matrix[ctoi(keypad[3])][ctoi(keypad[0])] = 1;
	matrix[ctoi(keypad[3])][ctoi(keypad[6])] = 1;
	matrix[ctoi(keypad[3])][ctoi(keypad[1])] = 1;
	matrix[ctoi(keypad[3])][ctoi(keypad[7])] = 1;
	matrix[ctoi(keypad[3])][ctoi(keypad[4])] = 1;
	
	// 5 -> 2
	// 5 -> 8
	// 5 -> 1
	// 5 -> 7
	// 5 -> 4
	matrix[ctoi(keypad[5])][ctoi(keypad[2])] = 1;
	matrix[ctoi(keypad[5])][ctoi(keypad[8])] = 1;
	matrix[ctoi(keypad[5])][ctoi(keypad[1])] = 1;
	matrix[ctoi(keypad[5])][ctoi(keypad[7])] = 1;
	matrix[ctoi(keypad[5])][ctoi(keypad[4])] = 1;
	
	// 7 -> 6
	// 7 -> 8
	// 7 -> 3
	// 7 -> 5
	// 7 -> 4
	matrix[ctoi(keypad[7])][ctoi(keypad[6])] = 1;
	matrix[ctoi(keypad[7])][ctoi(keypad[8])] = 1;
	matrix[ctoi(keypad[7])][ctoi(keypad[3])] = 1;
	matrix[ctoi(keypad[7])][ctoi(keypad[5])] = 1;
	matrix[ctoi(keypad[7])][ctoi(keypad[4])] = 1;
	
	//Centre Piece: 4
	//4 -> 0
	//4 -> 2
	//4 -> 6
	//4 -> 8
	
	//4 -> 1
	//4 -> 3
	//4 -> 4
	//4 -> 7
	
	matrix[ctoi(keypad[4])][ctoi(keypad[0])] = 1;
	matrix[ctoi(keypad[4])][ctoi(keypad[2])] = 1;
	matrix[ctoi(keypad[4])][ctoi(keypad[6])] = 1;
	matrix[ctoi(keypad[4])][ctoi(keypad[8])] = 1;
	
	matrix[ctoi(keypad[4])][ctoi(keypad[1])] = 1;
	matrix[ctoi(keypad[4])][ctoi(keypad[3])] = 1;
	matrix[ctoi(keypad[4])][ctoi(keypad[4])] = 1;
	matrix[ctoi(keypad[4])][ctoi(keypad[7])] = 1;
	
	return matrix; 
}

int bfs(vector<vector<int>> &adjMat, int start, int end){
	vector<bool> visited(10, false);
	
	queue<pair<int, int>> q; 
	
	q.push({start, 0});
	visited[start] = true; 
	
	while(!q.empty()){
		pair<int, int> curr = q.front();
		q.pop(); 
		
		for(int i=1;i<10;i++){
			if(adjMat[curr.first][i] == 1 && (!visited[i])){
				if(i == end) return curr.second + 1; 
				q.push({i, (curr.second + 1)});
				visited[i] = true; 
			}
		}
	}
	return -1; 
}

int getMinTime(string keypad, string code){
	vector<vector<int>> adjMat = getAdjMat(keypad);
	
	int totalTime; 
	for(int i=1;i<code.length();++i)
		totalTime += bfs(adjMat, ctoi(code[i-1]), ctoi(code[i]));
	
	return totalTime; 
}

int main(){
	string keypad = "923857614";
	string code = "423692";
	
	cout<<getMinTime(keypad, code)<<endl;
	
	return 0;  
}
