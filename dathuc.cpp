#include <iostream>
using namespace std;

struct node{
    float heso;
    int somu;
    node* link;
};

struct ListDT{
    node* first, *last;
};
//khoi tao danh sach da thuc
void initDT(ListDT *l){
    l->first=l->last=NULL;
}

//tao mot node moi
node* callNode(float hs, int sm){
    node* p;
    p = new node;
    if (p==NULL)    return NULL;    //ktra xem cap phat bo nho cho p co thanhcong khong, p =null la that bai
    p->heso= hs;
    p->somu= sm;
    p->link=NULL;
    return p;
}

//gan node p vao danh sach
void addNode(ListDT *lDT,node*p){
    if(lDT->first==NULL) {//danh sach rong
        lDT->first=lDT->last=p;     //vidu voi ptu nhap vao dau tien
    }else{
        lDT->last->link=p;      //gan next cua nut cuoi la p
        lDT->last=p;            //bien nut cuoi la nut p

    }
}

//them node voi he so va so mu cho truoc
void attachNode(ListDT *lDT,float hs, int sm){
    node*p = callNode(hs,sm);       //tao nut p voi du lieu tren
    if(p==NULL)  return;             //neu tao node that bai thi ket thuc ham
    addNode(lDT, p);              //them p vua tao vao ds
}

//tao da thuc
void nhapDT(ListDT *l){
    float hs; int sm;
    int i=0;        //dem so phan tu
    cout<<"Bat dau nhap da thuc (nhap he so 0 de ket thuc): "<<endl;
    do{
        i++;
        cout<< "Nhap phan tu thu "<<i<<endl;
        cout<<"Nhap he so: ";   cin>>hs;
        //ktr he so nhap vao bang 0 thi ket thuc
        if(hs==0) break;
        cout << "\nNhap so mu: "; cin>>sm;
        attachNode(l,hs,sm);    //khong can & vi l da la con tro r
    }   while(hs!=0);
    cout<<"Da nhap xong"<<endl;
}

void inDT(ListDT *l){
    node*p;
    p=l->first;
    cout<<"f(x)= ";
    while (p!=NULL){
        cout<<p->heso<<"* x^"<<p->somu;
        if(p->link !=NULL && p->heso!=0)
        cout<<" + ";
        p=p->link;
    }
}
int main(){
    ListDT dt;
    initDT(&dt);
    nhapDT(&dt);
    inDT(&dt);
}