using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PacketMaker
{
    class Program
    {
        static string patch_ = "D:\\workspace_vs";
        static string serverProjectName_ = "\\ServerCore\\ServerLibrary";
        static string serverProjectPath_ = patch_ + serverProjectName_ + "\\Net\\Packet";

        static string clientProjectName_ = "\\DummyClient";
        static string clientProjectPath_ = patch_ + clientProjectName_ + "\\Source\\PacketGen";

        static string excelPath_ = patch_ + "\\ServerCore\\PacketRule.xlsx";
        static string dataSheet_ = "PacketData";

        static void Main(string[] args)
        {
            Console.WriteLine("* Packet Maker running");
            ClassMakePacket serverClass = new ClassMakePacket(excelPath_, "PacketClass");
            serverClass.make(dataSheet_, serverProjectPath_ + "\\PacketClass.h");

            HeaderMakePacket serverHeader = new HeaderMakePacket(excelPath_, "PacketHeader");
            serverHeader.make(dataSheet_, serverProjectPath_ + "\\PacketHeader.h");

            FactoryMakePacket serverFactory = new FactoryMakePacket(excelPath_, "PacketFactory");
            serverFactory.make(dataSheet_, serverProjectPath_ + "\\PacketFactory.h");

            HeaderMakePacket clientHeader = new HeaderMakePacket(excelPath_, "ClientPacketHeader");
            clientHeader.make(dataSheet_, clientProjectPath_ + "\\PacketHeader.cs");

            ClientClassMakePacket clientClass = new ClientClassMakePacket(excelPath_, "ClientPacketClass");
            clientClass.make(dataSheet_, clientProjectPath_ + "\\PacketClass.cs");

            FactoryMakePacket clientFactory = new FactoryMakePacket(excelPath_, "ClientPacketFactory");
            clientFactory.make(dataSheet_, clientProjectPath_ + "\\PacketFactory.cs");
        }
    }
}
