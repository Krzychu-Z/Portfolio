#include <iostream>

using namespace std;

class CD{
protected:
	char *content_;
	bool consc_;
	size_t memory_;
	friend class BR;
public:
	CD();

	CD(char*);

	CD(const CD&);

	~CD();

	void read();

	void in_out();
};

class CDRW : public CD{
public:
	void write();
};

class BR : public CDRW{
public:
	BR();

	BR(const CD&);

	BR(const BR&);
};

CD::CD(){
	memory_ = 10;
	content_ = new char[memory_]();
	consc_ = false;
}

CD::CD(char* ptr){
	memory_ = 10;
	content_ = new char[memory_];
	consc_ = false;

	//Copy from given array first ten elements (write them on a CD)
	for(size_t i = 0; i < 10; i++){
		if( i != 9){
			content_[i] = *ptr;
			ptr++;
		} else {
			content_[i] = *ptr;
		}
	}
	ptr -= 9;
}

CD::CD(const CD &source){
	consc_ = source.consc_;
	memory_ = 10;

	content_ = new char[memory_];

	cout << "Copy constructor evoked" << endl;
	//Copy from given CD ten elements (write them on a CD)
	for(size_t i = 0; i < memory_; i++){
		content_[i] = source.content_[i];
	}
}

CD::~CD(){
	delete[] content_;
	cout << "Destructor evoked" << endl;
}

void CD::read(){
	if(consc_){
		for(size_t i = 0; i < memory_; i++){
			cout << "Data no " << i + 1 << ": " << content_[i] << endl;
		}
	} else {
		cout << "You need to insert CD into reader first" << endl;
	}
}

void CD::in_out(){
	if(consc_){
		consc_ = false;
	} else {
		consc_ = true;
	}
}

void CDRW::write(){
	if(consc_){
		for(size_t i = 0; i < memory_; i++){
			cout << "Data no " << i + 1 << ": ";
			cin >> content_[i];
		}
	} else {
		cout << "You need to insert CDRW into station first" << endl;
	}
}

BR::BR(){
	memory_ = 20;
	content_ = new char[memory_]();
	consc_ = false;
}

BR::BR(const CD &source){
	consc_ = source.consc_;
	memory_ = 20;

	content_ = new char[memory_];

	cout << "Copy constructor evoked" << endl;
	//Copy from given CD ten elements (write them on a CD)
	for(size_t i = 0; i < 10; i++){
		content_[i] = source.content_[i];
	}
	for(size_t i = 10; i < 20; i++){
		content_[i] = 0;
	}
}

BR::BR(const BR &source){
	consc_ = source.consc_;
	memory_ = 20;

	content_ = new char[memory_];

	cout << "Copy constructor evoked" << endl;
	//Copy from given CD ten elements (write them on a CD)
	for(size_t i = 0; i < memory_; i++){
		content_[i] = source.content_[i];
	}
}
