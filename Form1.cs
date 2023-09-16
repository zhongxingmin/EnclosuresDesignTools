using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SQLite;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EnclosuresDesignTools
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            SQLLiteServer.Init();

            string query = "SELECT * FROM block_tb";
            SQLiteConnection LocalDbConnection = SQLLiteServer.LocalDbConnection;
            SQLiteCommand command = new SQLiteCommand(query, LocalDbConnection);

            // 执行查询并获取结果集
            SQLiteDataReader reader = command.ExecuteReader();


            while (reader.Read())
            {
                // 获取需要显示在 TreeView 上的数据，例如父节点和子节点值
                string parentNodeValue = reader.GetString(2);  // 根据实际数据类型和列索引进行调整
                string childNodeValue = reader.GetString(1);

                // 查找现有节点或创建新节点
                TreeNode[] parentNodes = treeView1.Nodes.Find(parentNodeValue, true);

                if (parentNodes.Length > 0)
                {
                    // 父节点已存在，将子节点添加到现有父节点
                    parentNodes[0].Nodes.Add(childNodeValue);
                }
                else
                {
                    // 父节点不存在，创建新的父节点并添加子节点
                    TreeNode parentNode = treeView1.Nodes.Add(parentNodeValue);
                    parentNode.Nodes.Add(childNodeValue);
                }
            }


        }
    }
}
