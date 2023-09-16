using System;
using System.Windows.Forms;
using GrxCAD.Runtime;
using GrxCAD.ApplicationServices;
using GrxCAD.DatabaseServices;
using GrxCAD.EditorInput;
using GrxCAD.Geometry;
using System.IO;
using EnclosuresDesignTools;

namespace EnclosuresDesignTools
{


    public partial class MainForm : Form
    {
        private Document doc;

        public MainForm()
        {
            InitializeComponent();

            // 获取当前文档对象
            doc = GrxCAD.ApplicationServices.Application.DocumentManager.MdiActiveDocument;
        }
        public class Filepath
        {
            public static string dllPath = typeof(DialogCommand).Assembly.Location;
            public static string directoryPath = Path.GetDirectoryName(dllPath);
        }



        private void button1_Click(object sender, EventArgs e)
        {
            // 获取当前数据库对象
            Database db = doc.Database;

            // 获取当前编辑器对象
            Editor editor = doc.Editor;

            // 提示用户选择插入点
            PromptPointResult result = editor.GetPoint("Select insertion point: ");
            if (result.Status == PromptStatus.OK)
            {
                Point3d insertionPoint = result.Value;

                // 指定图块的名称和路径
                string blockName = "BlockName";
                string subFolder = "Block";
                string blockPath = Path.Combine(Filepath.directoryPath, subFolder, "Block.dwg");
                

                // 打开图块文件并复制图块定义到当前数据库
                using (Transaction tr = db.TransactionManager.StartTransaction())
                {
                    BlockTable bt = tr.GetObject(db.BlockTableId, OpenMode.ForRead) as BlockTable;
                    BlockTableRecord modelSpace = tr.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForWrite) as BlockTableRecord;

                    // 检查图块是否已经存在于当前数据库中X
                    if (!bt.Has(blockName))
                    {
                        // 插入图块
                        using (Database sourceDb = new Database(false, true))
                        {
                            sourceDb.ReadDwgFile(blockPath, FileOpenMode.OpenForReadAndAllShare, false, null);

                            ObjectIdCollection ids = new ObjectIdCollection();
                            using (Transaction trans = sourceDb.TransactionManager.StartTransaction())
                            {
                                BlockTable btSource = trans.GetObject(sourceDb.BlockTableId, OpenMode.ForRead) as BlockTable;
                                BlockTableRecord btrSource = trans.GetObject(btSource[blockName], OpenMode.ForRead) as BlockTableRecord;
                                ids.Add(btrSource.ObjectId);
                                trans.Commit();
                            }

                            db.WblockCloneObjects(ids, bt.ObjectId, new IdMapping(), DuplicateRecordCloning.Ignore, false);
                        }
                    }

                    // 在指定插入点插入图块参照
                    BlockReference blockRef = new BlockReference(insertionPoint, bt[blockName]);
                    modelSpace.AppendEntity(blockRef);
                    tr.AddNewlyCreatedDBObject(blockRef, true);

                    tr.Commit();
                }

                editor.WriteMessage("Block inserted successfully.");
            }




        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            SQLLiteServer.Init();
            //获取桌面宽度
            int nDeskWidth = Screen.PrimaryScreen.WorkingArea.Width;
            //获取桌面高度
            //int nDeskHeight = Screen.PrimaryScreen.WorkingArea.Height;
            //设置窗体宽度
            //this.Width = Convert.ToInt32(nDeskWidth * 0.8);
            //设置窗体高度
            //this.Height = Convert.ToInt32(nDeskHeight * 0.8);         
            this.SetDesktopLocation(Convert.ToInt32(nDeskWidth * 0.75), 50);





        }

        private void button2_Click(object sender, EventArgs e)
        {
            // 创建第二个窗口对象并显示它
            Form1 window2 = new Form1();
            window2.Show();
        }
    }
}
