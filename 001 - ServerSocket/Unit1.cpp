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
    //視窗建立就啟動Server
    ServerSocket1->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    //當有人連線時
    Memo1->Lines->Add(Socket->RemoteAddress + ":" +IntToStr(Socket->RemotePort) + " Connect.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
    //當有人離線時
    Memo1->Lines->Add(Socket->RemoteAddress + ":" +IntToStr(Socket->RemotePort) + " Disconnect.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
    //收到的訊息(收完即清空)
    AnsiString Msg = Socket->ReceiveText();
    //顯示收到的訊息
    Memo1->Lines->Add("Read:" + Msg);
    //向所有人發送訊息
    SendToAll(Socket->RemoteAddress + ":" +IntToStr(Socket->RemotePort) + ":" + Msg);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SendToAll(AnsiString Msg)
{
    //向所有人發送訊息
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
    //當有使用者異常斷線
    if(ErrorCode==10053)
    {
        //僅顯示
        Memo1->Lines->Add("Client Disconnect Error.");
        //清除異常，否則會丟出Exception
        ErrorCode=0;
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ServerSocket1Accept(TObject *Sender,
      TCustomWinSocket *Socket)
{
    //歡迎訊息
    Socket->SendText("Hello! Wellcome to Socket Server.");
}
//---------------------------------------------------------------------------

