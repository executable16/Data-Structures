// Left = Anticlockwise
// Right = Clockwwise
// Reference : https://www.geeksforgeeks.org/left-rotation-right-rotation-string-2/
void leftrotate(string &s, int d) 
{ 
	reverse(s.begin(), s.begin()+d); 
	reverse(s.begin()+d, s.end()); 
	reverse(s.begin(), s.end()); 
}

void rightrotate(string &s, int d) 
{ 
leftrotate(s, s.length()-d); 
} 
