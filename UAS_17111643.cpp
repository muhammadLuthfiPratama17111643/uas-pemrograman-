#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;


void gotoxy(int x,int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


class Teller_Bank
	{
		private :
					typedef struct Tnode
					{
						string data;
						int no;
						Tnode *next;
					}data;

					typedef struct Pnode
					{
						string nama;
						string norek;
						string jentran;
						int jumtran;
						Pnode *Pnext;
					}Pdata;
					
					typedef struct Snode
					{
						string nama;
						string norek;
						string jentran;
						int jumtran;
						Snode *Snext;
					}Sdata;

					int noan=1;
					int count=0;
					int post;
					Pnode *Phead;
					Snode *Shead;
					Tnode *head;
					Tnode *bantu;
					Tnode *hapus;
					struct PNode **Phead_ref;
  					struct Node* new_node      ;
	public :

		Teller_Bank();
		int IsEmpty();
		int PsEmpty();
		void Menu();
		void Delete();
		void deletemid(int post);
		void cari(int post);
		void updatemid(int post,string norek,string jentran,int jumtran);
		void sorting();
	 	void insert_antrian(string nama);
		void insertpesanan(string norek,string jentran,int jumtran);
		void tampilantrian();
		void tampilpesanan();
		void show_working();
		void insertionSort( Snode **Phead_ref);
		void sortedInsert( Snode	**Phead_ref,  Snode* new_node)  ;
		void printList( Snode *Phead_);
};



int Teller_Bank::IsEmpty()
	{
		if(head==NULL)
		return 1;
		else
		return 0;
	}

int Teller_Bank::PsEmpty()
	{
		if(Phead==NULL)
		return 1;
		else
		return 0;
	}
void Teller_Bank::printList(struct Snode *Phead_)
{
	int no=1;
	int xx=10;
    Snode *temp = Phead_;
    while(temp != NULL)
    {
	   //gotoxy(14,xx);
			   cout<<endl;
			cout<<no<<" "<<temp->nama<<endl;
			//gotoxy(17,xx+1);
			cout<<"Nomor Rekening : "<<temp->norek;
			//gotoxy(17,xx+2);
			cout<<", Jenis Transaksi : "<<temp->jentran;
			//gotoxy(17,xx+3);
			cout<<", Jumlah Transaksi : "<<temp->jumtran;
			temp=temp->Snext;
			xx=xx+6;
			no++; cout<<endl;

    }
}

void Teller_Bank::insertionSort( struct Snode **Phead_ref)
{
    // Initialize sorted linked list
     struct Snode *sorted = NULL;

    // Traverse the given linked list and insert every
    // node to sorted
     struct Snode *current = *Phead_ref;
    while (current != NULL)
    {
        // Store next for next iteration
         struct Snode *Snext = current->Snext;

        // insert current in sorted linked list
        sortedInsert(&sorted, current);

        // Update current
        current = Snext;
    }

    // Update head_ref to point to sorted linked list
    *Phead_ref = sorted;
}

void Teller_Bank::sortedInsert(struct Snode** Phead_ref, struct Snode* new_node)
{
    struct Snode* current;
    /* Special case for the head end */
    if (*Phead_ref == NULL || (*Phead_ref)->jumtran >= new_node->jumtran)
    {
        new_node->Snext = *Phead_ref;
        *Phead_ref = new_node;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = *Phead_ref;
        while (current->Snext!=NULL &&
               current->Snext->jumtran < new_node->jumtran)
        {
            current = current->Snext;
        }
        new_node->Snext = current->Snext;
        current->Snext = new_node;
    }
}

Teller_Bank::Teller_Bank(){
	   head=NULL;
	   Phead=NULL;
	   Shead=NULL;
	   bantu=NULL;
}

void Teller_Bank::Delete()
{
 Tnode *hapus;
	string d;


	if(bantu==NULL)
	bantu = head;


	if(IsEmpty()==0)
	{
		if(head!=NULL)
		{
			noan=noan+1;
			hapus=head;
			d=hapus->data;
			head=hapus->next;
		}

	}else
	cout<<"\nMasih Kosong\n";
}

void Teller_Bank::deletemid(int post)
{
	Pnode *current = new Pnode;
	Pnode *previous = new Pnode;

	Tnode *Tcurrent = new Tnode;
	Tnode *Tprevious = new Tnode;

	Tcurrent=bantu;
	current = Phead;
	for(int i=1;i<post;i++)
	{
		previous=current;
		current=current->Pnext;
		Tprevious=Tcurrent;
		Tcurrent=Tcurrent->next;
	}
	if(post==1)
	{
		Phead=Phead->Pnext;
	}else{
		
	previous->Pnext=current->Pnext;
	Tprevious->next=Tcurrent->next;
	}
	cout<<" Data Terhapus "<<endl;
	count--;
}

void Teller_Bank::updatemid(int post,string norek, string jentran, int jumtran)
{
	Pnode *Pbaru,*Pbantu;
	Pbaru = new Pnode;

	Pbaru->norek = norek;
	Pbaru->jentran = jentran;
	Pbaru->jumtran = jumtran;
	Pbaru->Pnext = NULL;

	Pnode *current = new Pnode;
	Pnode *previous = new Pnode;


	//Tnode *Tcurrent = new Tnode;
	//Tnode *Tprevious = new Tnode;

	//Tcurrent=bantu;
	current = Phead;
	for(int i=1;i<post;i++)
	{
		previous=current;
		current=current->Pnext;

	}
	Pbaru->nama=current->nama;
	if(post!=1)
 	{
		previous->Pnext=Pbaru; Pbaru->Pnext=current->Pnext;
 	}
 	
	else
	{
		   Pbaru->Pnext = current->Pnext;

		   Phead = Pbaru;
	}

	//Tprevious->next=Tcurrent->next;
}

void Teller_Bank::cari(int post)
{
	int no=1;
 	Tnode *antu;
	Pnode *Pbantu;

	Pbantu = Phead;
	antu=bantu;
	if(PsEmpty()==0)
	{
		int xx=20;

		for(int a=1;a<post;a++)
		{
			no++;
			Pbantu=Pbantu->Pnext;
			antu=antu->next;
		}


			gotoxy(14,xx);
			cout<<no<<" "<<antu->data<<endl;
			gotoxy(17,xx+1);
			cout<<"Nomor Rekening : "<<Pbantu->norek;
			gotoxy(17,xx+2);
			cout<<"Jenis Transaksi : "<<Pbantu->jentran;
			gotoxy(17,xx+3);
			cout<<"Jumlah Transaksi : "<<Pbantu->jumtran;

	}else{
		gotoxy(15,15);cout<<"Masih Kosong"<<endl;
	}

}

void Teller_Bank::sorting()
{

}

void Teller_Bank::insert_antrian(string nama)
{
	int x=0;
	Tnode *baru,*Tbantu;
	baru = new Tnode;
	baru->data = nama;
	baru->next = NULL;

			if(head==NULL && bantu!=NULL)
			{
				head=bantu;
				x=7;
			}



	if(IsEmpty()==1)
	{
		head=baru;
		head->next = NULL;
	}else
	{
		Tbantu = head;
		while(Tbantu->next!=NULL)
		{
			Tbantu=Tbantu->next;
		}
		Tbantu->next=baru;
	}
	gotoxy(15,15);
	cout<<"Data Terisi";

	if(x==7)
	{
		head=Tbantu->next;
	}
}




void Teller_Bank::insertpesanan(string norek, string jentran, int jumtran)
{

 	Pnode *Pbaru,*Pbantu;
 	Snode *Sbaru, *Sbantu;


	Sbaru = new Snode;
	Sbaru->nama=head->data;
	Sbaru->norek = norek;
	Sbaru->jentran = jentran;
	Sbaru->jumtran = jumtran;
	Sbaru->Snext = NULL;


	Pbaru = new Pnode;
	Pbaru->nama=head->data;
	Pbaru->norek = norek;
	Pbaru->jentran = jentran;
	Pbaru->jumtran = jumtran;
	Pbaru->Pnext = NULL;


	if(PsEmpty()==1)
	{
		 //Pbaru->nama = Tbantu->data;
		Phead=Pbaru;
		Phead->Pnext = NULL;
		
		
		Shead=Sbaru;
		Shead->Snext = NULL;

	}else
	{
		  Pbantu = Phead;
		  Sbantu = Shead;
		while(Pbantu->Pnext!=NULL)
				{
					Sbantu=Sbantu->Snext;
					Pbantu=Pbantu->Pnext;
				}
		//while(Tbantu->next!=NULL)
		//		{
   		//			Tbantu=Tbantu->next;
		//		}

//Pbaru->nama = Tbantu->data;

Sbantu->Snext=Sbaru;

  Pbantu->Pnext=Pbaru;
  

	}
	gotoxy(25,21);
	count++;
	cout<<"Data Terisi";

}

void Teller_Bank:: tampilantrian()
{
	int no=noan;

 	Tnode *cantu;

	cantu = head;
	if(IsEmpty()==0)
	{
		int xx=10;
		while(cantu!=NULL)
		{
			gotoxy(17,xx);
			cout<<no<<" "<<cantu->data<<endl;
			cantu=cantu->next;
			no++;   xx=xx+2;
		}
	}else
	{
		gotoxy(15,15);
		cout<<"Masih Kosong";
		gotoxy(15,17);
		cout<<"Silahkan Input Antrian Terlebih Dahulu"<<endl;
	}

}

void Teller_Bank::tampilpesanan()
{
	int no=1;

	Pnode *Pbantu;

	Pbantu = Phead;

	if(PsEmpty()==0)
	{
		int xx=10;
		while(Pbantu!=NULL)
		{
			gotoxy(14,xx);
			cout<<no<<" "<<Pbantu->nama<<endl;
			gotoxy(17,xx+1);
			cout<<"Nomor Rekening : "<<Pbantu->norek;
			gotoxy(17,xx+2);
			cout<<"Jenis Transaksi : "<<Pbantu->jentran;
			gotoxy(17,xx+3);
			cout<<"Jumlah Transaksi : "<<Pbantu->jumtran;
			Pbantu=Pbantu->Pnext;

			xx=xx+6;
			no++; cout<<endl;
		}
	}else{
		gotoxy(15,15);cout<<"Masih Kosong"<<endl;
	}
}

void Teller_Bank::Menu()
{
		gotoxy(3,3);
		cout<<"************** Selamat Datang di Bank informatika 11 ***************"<<endl;
		gotoxy(3,4);
		cout<<"************ Universitas Amikom Yogyakarta ************"<<endl;
		gotoxy(5,6);
		cout<<"Masukan Pilihan "<<endl;
		gotoxy(11,8);
		cout<<"1. Input Antrian\n";
		gotoxy(11,10);
		cout<<"2. Daftar Antrian\n";
		gotoxy(11,12);
		cout<<"3. Panggil Antrian\n";
		gotoxy(11,14);
		cout<<"4. Daftar Antrian Terpanggil \n";
		gotoxy(11,16);
		cout<<"5. Hapus , Ubah , Urutkan , Cari\n";
		gotoxy(11,18);
		cout<<"6. Tentang Aplikasi\n";
		gotoxy(11,20);
		cout<<"7. Exit"<<endl;


}


void Teller_Bank::show_working()
{
	Snode *a = NULL;
	a=new Snode;
	int jumtrans,pil,pil2,pos,urutan=0;
	char jt;
	string xnama,name,z,jentrans;
	do{
		Menu();  gotoxy(5,22);
		cout<<"Masukkan Pilihan : "; cin>>pil;
		cout<<"\n\n\n\n";
		system("cls");

		switch(pil)
		{
			case 1 :

				gotoxy(3,3);
				cout<<"************** Selamat Datang di Bank informatika 11 ***************"<<endl;
				gotoxy(3,4);
				cout<<"************ Universitas Amikom Yogyakarta ************"<<endl;
				gotoxy(11,8);
				cout<<" Input Antrian\n";
				gotoxy(15,10);
				cout<<"Masukan Data : "; cin>>name;
				IsEmpty();
                insert_antrian(name);

			break;

			case 2 :

			gotoxy(3,3);
   			cout<<"************** Selamat Datang di Bank informatika 11 ***************"<<endl;
			gotoxy(3,4);
			cout<<"************ Universitas Amikom Yogyakarta ************"<<endl;

			gotoxy(11,8);
			cout<<" Daftar Antrian\n";
			IsEmpty();
			tampilantrian();

			break;

			case 3 :

			gotoxy(3,3);
   			cout<<"************** Selamat Datang di Bank informatika 11 ***************"<<endl;
			gotoxy(3,4);
			cout<<"************ Universitas Amikom Yogyakarta ************"<<endl;
			gotoxy(11,8);
			cout<<" Panggil Antrian\n";

			IsEmpty();
			if(IsEmpty()==0)
				{
						Tnode *cantu;
						cantu= new Tnode;
						cantu = head;
						gotoxy(9,10);
						cout<<"Silahkan Mengisi Data kepada "<<cantu->data<<endl;
						gotoxy(9,12);
						cout<<"Nomor Rekening : "; cin>>z;
						gotoxy(9,14);
						cout<<"Jenis Transaksi : \n";
						gotoxy(9,15);
						cout<<"A.Debet\n";
						gotoxy(9,16);
						cout<<"B.Kredit\n";
						gotoxy(9,17);
						cout<<"Pilihan (A/B/a/b) :"; cin>>jt;
						gotoxy(9,19);
						cout<<"Jumlah Transaksi : "; cin>>jumtrans;

						if(jt=='a' || jt=='A')
			                {
			                    jentrans=" Debet";
			                }
				        else if(jt=='b' || jt=='B')
				                {
				                    jentrans=" Kredit";
				                }
				        urutan++;
						insertpesanan(z,jentrans,jumtrans);
						Delete();
				}else
				{
					gotoxy(15,15);
					cout<<"Masih Kosong";
				}

			break;

			case 4 :

			gotoxy(3,3);
   			cout<<"************** Selamat Datang di Bank informatika 11 ***************"<<endl;
			gotoxy(3,4);
			cout<<"************ Universitas Amikom Yogyakarta ************"<<endl;
			gotoxy(11,8);
			cout<<" Daftar Antrian Terpanggil \n";
			PsEmpty();
			tampilpesanan();

			break;

			case 5 :
						 if(Phead!=NULL)
								{
									gotoxy(3,3);
						  			cout<<"************** Selamat Datang di Bank informatika 11 ***************"<<endl;
									gotoxy(3,4);
									cout<<"************ Universitas Amikom Yogyakarta ************"<<endl;

									cout<<"Edit\n";
									cout<<"1. Hapus Data tertentu"<<endl;
									cout<<"2. Ubah Data Tertentu"<<endl;
									cout<<"3. Urutkan Data Berdasarkan Jumlah Transaksi"<<endl;
									cout<<"4. Cari berdasarkan Nomor Antrian"<<endl;
									cout<<"5. Hapus Keseluruhan Data"<<endl;
									cout<<"Pilihan : "; cin>>pil2;

									switch(pil2)
									{
										case 1 :
													cout<<"Hapus Data Tertentu\n\n"<<endl;
							   						cout<<"Saat data terhapus\n";
							   						cout<<"Nomor antrian Terpanggil dibelakangnya akan\n";
							   						cout<<"Maju satu langkah"<<endl;
													cout<<"Posisi berapa yang di hapus ? "; cin>>pos;
													if(count>=pos) {
													deletemid(pos);
													urutan--;
													}
													else
													cout<<" Data Kosong Pada Nomore Tersebut " <<endl;
													
										break;

										case 2 :
													cout<<"Ubah Data Tertentu\n";
													cout<<"Posisi berapa yang diupdate ? "; cin>>pos;

													if(pos>urutan)
																{
						  											cout<<"Kosong"<<endl;
																}
													else
																{
																		cari(pos);
																	//xnama=antu->data;
																		cout<<"\n\nSilahkan Mengisi Data Baru "<<endl;
																			//gotoxy(,12);
																			cout<<"		Nomor Rekening : "; cin>>z;
																			//gotoxy(9,14);
																			cout<<"		Jenis Transaksi : \n";
																			//gotoxy(9,15);
																			cout<<"		A.Debet\n";
																			//gotoxy(9,16);
																			cout<<"		B.Kredit\n";
																			//gotoxy(9,17);
																			cout<<"		Pilihan (A/B/a/b) :"; cin>>jt;
																			//gotoxy(9,19);
																			cout<<"		Jumlah Transaksi : "; cin>>jumtrans;

																			if(jt=='a' || jt=='A')
																                {
																                    jentrans=" Debet";
																                }
																	        else if(jt=='b' || jt=='B')
																	            {
																	                    jentrans=" Kredit";
																	            }
																		updatemid(pos,z,jentrans,jumtrans);
																}
										break;

										case 3 :
													cout<<"Urutkan Berdasarkan Jumlah Transaksi";
													

			 											a=Shead;

														insertionSort(&a);
														printList(a);
														
													cout<<"Setelah data diurutkan, maka dilarang menginputkan data lagi.";
										break;

										case 4 :   cout<<"CARI berdasarkan Nomor Antrian"<<endl;
													cout<<"Masukan Nomor Antrian = "; cin>>pos;
			 											if(pos>urutan)
													{
			  											cout<<"Kosong"<<endl;
													}	else
													cari(pos);
										break;

										case 5 :
													cout<<"Hapus Keseluruhan Data"<<endl;
													head=NULL;
													bantu=NULL;
													Phead=NULL;
													noan=1;
													gotoxy(15,15);cout<<"Data Kosong\n\n";
										break;
									}

								}
								else
								{
									
																gotoxy(3,3);
						   			cout<<"************** Selamat Datang di Bank informatika 11 ***************"<<endl;
									gotoxy(3,4);
									cout<<"************ Universitas Amikom Yogyakarta ************"<<endl;
									
									
									cout<<"\n\n\t\t\tAntrian Terpanggil Masih kosong "<<endl;
									
									
								}

			break;

			case 6 :

				gotoxy(3,3);
	  			cout<<"************** Selamat Datang di Bank informatika 11 ***************"<<endl;
				gotoxy(3,4);
				cout<<"************ Universitas Amikom Yogyakarta ************"<<endl;
				gotoxy(7,7);cout<<"Aplikasi ini dibuat untuk memenuhi tugas pemograman\n";
				gotoxy(7,9);cout<<"                      1643";
				gotoxy(7,11);cout<<"\tMuhammad Luthfi p";

			break;

			case 7 :

			gotoxy(5,5);
			cout<<"Good Bye-Bye"<<endl;

			break;

			default :

			gotoxy(3,3);
			cout<<"************** Selamat Datang di Bank informatika 11 ***************"<<endl;
			gotoxy(3,4);
			cout<<"************ Universitas Amikom Yogyakarta ************"<<endl;
			gotoxy(5,7);
			cout<<"Anda Salah Menginputkan Data"<<endl;

		}
		cout<<endl;

		cout<<"\n\n\n		Lanjut";
		getch();
	system("cls");
	}while(pil!=7);

}




int main(int argc, char** argv)
{
	Teller_Bank object;
	object.show_working();

	return 0;
}
