#include<iostream>
#include<memory>

using namespace std;
struct node {
	int data;
	std::unique_ptr<node> port;
	std::unique_ptr<node> starboard;
	node(int a) {
		data = a;
		port = nullptr;
		starboard = nullptr;
	}
};
std::unique_ptr<node> root;

class make {
public:
	node* helper;
	make() 
	{
		helper = nullptr;
		root = nullptr;
	}
	void add(int a)
	{
		auto in = std::make_unique<node>(a);
		if (root == nullptr) {
			root = std::move(in);
			helper = in.get();
		}
		else
		{
			helper = root.get();
			int u = 0, p = 0;
			bool sr, pr;
			while (true)
			{
				sr = false;
				pr = false;
				u = 0;
				while (a <= helper->data && helper->port )
				{
					helper = helper->port.get();
					u++;
					pr = true;

				}
				p = 0;
				while (a > helper->data && helper->starboard )
				{
					helper = helper->starboard.get();
					p++;
					sr = true;

				}
				if (!(pr||sr)) { break;}
			

			}
	

			if (a <= helper->data)
			{
				helper->port = std::move(in);
				return;
			}
			if (a > helper->data)
			{
				helper->starboard = std::move(in);
			}
		}
	
	}
};
class support {
public:

	void pre(node* ancor) {
		if (ancor) {
			int i=0;
			node* kanan, * kiri;
			std::cout << ancor->data << " ";
			if (ancor->port ) {
				kiri = ancor;
				kiri = kiri->port.get();
				i++;
				pre(kiri);
			}
			if (ancor->starboard ) {
				kanan = ancor;
				kanan = kanan->starboard.get();
				i++;
				pre(kanan);
			}
		}

	}

	void in(node* ancor) {
		if (ancor) {
			node* kanan, * kiri;
			if (ancor->port) {
				kiri = ancor;
				kiri = kiri->port.get();
				in(kiri);
			}
			std::cout << ancor->data << " ";
			if (ancor->starboard) {
				kanan = ancor;
				kanan = kanan->starboard.get();
				in(kanan);
			}
		}
	}

	void las(node* ancor) {
		if (ancor) {
			node* kanan, * kiri;
			if (ancor->port) {
				kiri = ancor;
				kiri = kiri->port.get();
				las(kiri);
			}
			if (ancor->starboard) {
				kanan = ancor;
				kanan = kanan->starboard.get();
				las(kanan);
			}
			std::cout << ancor->data << " ";
		}
	}

	bool binary(int a) {
		node* bantu;
		bantu = root.get();
		bool s = false;
		bool p = false;
		if (bantu->data == a) { return true; }
		int i = 0;
		while (true)
		{
			s = false;
			p = false;
			if (bantu->data >= a && bantu->port) { bantu = bantu->port.get(); p = true; }
			if (bantu->data < a && bantu->starboard) { bantu = bantu->starboard.get(); s = true; }
			if (bantu->data == a) {  return true; }
			if (!(s || p)) { return false; }
			i++;
		}
		return false;
	}

	void bighick() 
	{
		node* bantu = root.get();
		while (bantu->starboard) 
		{
			bantu = bantu->starboard.get();
		}
		std::cout << "\n nilai terbesar :" << bantu->data << std::endl;
    }

    void lowhick(){
		node* bantu = root.get();
		while(bantu->port)
		{
			bantu = bantu->port.get();
		}
		std::cout << "\n nilai terkecil :" << bantu->data << std::endl;
	}
};
int main() {
	make in;
	support su;
    string bin;
    
    upper:

    int count = 1,pilihan,temp;
    
    std::cout << '\n' << '\n';
    std::cout << "1. penambahan node" << '\n';
    std::cout << "2. nilai terkecil" << '\n';
    std::cout << "3. nilai terbesar" << '\n';
    std::cout << "4. pencarian" << '\n';
    std::cout << "masukan pilihan = " ; std::cin >> pilihan;
    if (pilihan == 1){
        system("cls");
        std::cout << "Masukan Node : "; std::cin >> count;
        in.add(count); 
        system("cls");

        std::cout << "pre order \t: ";
	su.pre(root.get());
	std::cout << "\ninorder  \t: ";
	su.in(root.get());
	std::cout << "\nlastorder \t: ";
	su.las(root.get());
	    std::cout << std::endl;
        
        goto upper;
    }else if(pilihan == 2){
        system("cls");
        su.lowhick();
    }else if(pilihan == 3){
        system("cls");
        su.bighick();
    }else if(pilihan == 4){
        system("cls");
        std::cout << "masukan angka yang ingin dicari = ";
        std::cin >> temp;
        bin = su.binary(temp) ? "Bilangan Ditemukan":"Bilangan tidak Ditemukan";
        std::cout << '\n' <<bin << '\n';
    }else{
        system("cls");
        std::cout << "PILIHAN SALAH COBA LAGI!!!" << '\n';
    }
    
    std::cout << " \n index saat ini" << '\n' << '\n';

	std::cout << "pre order \t: ";
	su.pre(root.get());
	std::cout << "\ninorder  \t: ";
	su.in(root.get());
	std::cout << "\nlastorder \t: ";
	su.las(root.get());
	    std::cout << std::endl;

    goto upper;

}
