using System;
using GrxCAD.Runtime;
using GrxCAD.ApplicationServices;
using System.Windows.Forms;
using EnclosuresDesignTools;

namespace EnclosuresDesignTools
{
    public class DialogCommand
    {
        [CommandMethod("XM")]
        public void ShowHelloDialog()
        {
            // 调出主窗口
            MainForm form = new MainForm();
            GrxCAD.ApplicationServices.Application.ShowModelessDialog(form);

        }
    }
}
