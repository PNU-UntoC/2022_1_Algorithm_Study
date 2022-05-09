#include <iostream>
#include <algorithm>

using namespace std;

struct meet{
	int start_time, end_time;
};

bool comp(meet m1, meet m2){
	if (m1.end_time == m2.end_time){
		return m1.start_time < m2.start_time;
	}
	return m1.end_time < m2.end_time;
}
int main(void){
	int N;
	cin >> N;
	meet meeting[100000];
	for (int i=0; i<N; i++){
		cin >> meeting[i].start_time >> meeting[i].end_time;
	}
	
	sort(meeting, meeting+N, comp);
	
	int meeting_num=1, meeting_time=meeting[0].end_time;
	for (int i=1; i<N; i++){
			if (meeting_time <= meeting[i].start_time){
			meeting_time = meeting[i].end_time;
			meeting_num++;
		}
	}
	
	cout << meeting_num;
	
	return 0;
}
