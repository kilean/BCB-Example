//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    //�����إߴN�Ұ�Server
    ServerSocket1->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    //���H�s�u��
    Memo1->Lines->Add(Socket->RemoteAddress + ":" +IntToStr(Socket->RemotePort) + " Connect.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    //���H���u��
    Memo1->Lines->Add(Socket->RemoteAddress + ":" +IntToStr(Socket->RemotePort) + " Disconnect.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
    //���쪺�T��(�����Y�M��)
    AnsiString Msg = Socket->ReceiveText();
    //��ܦ��쪺�T��
    Memo1->Lines->Add("Read:" + Msg);
    //�V�Ҧ��H�o�e�T��
    SendToAll(Socket->RemoteAddress + ":" +IntToStr(Socket->RemotePort) + ":" + Msg);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SendToAll(AnsiString Msg)
{
    //�V�Ҧ��H�o�e�T��
    int count = ServerSocket1->Socket->ActiveConnections;
    for(int i = 0; i<count; i++)
    {
        ServerSocket1->Socket->Connections[i]->SendText(Msg);
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    //���ϥΪ̲��`�_�u
    if(ErrorCode==10053)
    {
        //�����
        Memo1->Lines->Add("Client Disconnect Error.");
        //�M�����`�A�_�h�|��XException
        ErrorCode=0;
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ServerSocket1Accept(TObject *Sender,
      TCustomWinSocket *Socket)
{
    //�w��T��
    Socket->SendText("Hello! Wellcome to Socket Server.");
}
//---------------------------------------------------------------------------

