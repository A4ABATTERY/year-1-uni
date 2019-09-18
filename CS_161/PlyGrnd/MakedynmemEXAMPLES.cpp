
int* makeDynMem(){
	mem = new int[5];
	delete[5]mem;
}
void makeDynMem2(int** mem){
	delete[1]mem;
}
void makeDynMem3(int*& mem){
	delete[1]mem;
}
int main(){
	mem* = 30

}
