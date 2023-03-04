#include <iostream>
#include <vector>


class Have{
public:
explicit Have(size_t len): length(len), data(new int[len]){
VVV.resize(len);}

~Have(){

if (data != nullptr){
delete[] data;
}
}

Have(const Have& orig): length(orig.length), data(new int[orig.length]){
VVV = orig.VVV;

copy(orig.data, orig.data + length, data);
}

Have& operator = (const Have& orig){
if (this != &orig){
delete[] data;

length = orig.length;
data = new int[length];
copy(orig.data, orig.data + length, data);

VVV = orig.VVV;
}
return *this;
}

size_t Length() const{
return length;
}

size_t length;
int* data;
vector<int> VVV;
};

class Reloc{
public:

Reloc(size_t len): length(len), data(new int[len]){
VVV.resize(len);}

~Reloc(){
if (data != nullptr){
delete[] data;
}
}

Reloc(Reloc&& orig) noexcept: data(nullptr), length(0){
data = orig.data;
length = orig.length;
VVV = orig.VVV;

orig.VVV.clear();
orig.data = nullptr;
orig.length = 0;
}

Reloc& operator = (Reloc&& orig) noexcept {
if (this != &orig){
delete[] data;

data = orig.data;
length = orig.length;
VVV = orig.VVV;

orig.VVV.clear();
orig.data = nullptr;
orig.length = 0;
}
return *this;
}


size_t Length() const{
return length;
}

size_t length;
int* data;
vector<int> VVV;
};


int main(){
Have Freddy(50);

for (int i = 0; i < 50; i++) {
Freddy.data[i] = 4;
}

Have Bryan(50);

Reloc Roger(50);
for (int i = 0; i < ; i++) {
Roger.data[i] = 1;
}

Reloc John(50);
Have E(Freddy);
std::cout << "Copied Freddy" << " ";
Freddy = Bryan;
std::cout << "Copied Freddy" << " ";
Reloc F(move(Roger));
std::cout << "Moved Roger" << " ";
Roger = move(John);
std::cout << "Moved Roger" << " ";
};

