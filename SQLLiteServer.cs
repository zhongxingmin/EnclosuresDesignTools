using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SQLite;
using System.IO;
using System.Linq;
using System.Text;
using System.Web;
using System.Windows.Forms;
using static EnclosuresDesignTools.MainForm;


namespace EnclosuresDesignTools
{
    public class SQLLiteServer
    {

        public static string dataFolder = "Data";
        public static string dataName = "MyDatabase.db";
        public static string dataFolderPath = Path.Combine(Filepath.directoryPath, dataFolder);
        public static string dataPath = Path.Combine(Filepath.directoryPath, dataFolder, dataName);
        // 创建连接字符串
       public static string connectionString = $"Data Source={dataPath};Version=3;";
        public static SQLiteConnection LocalDbConnection = null;

        // 建立数据库连接


        public static bool Init()
        {
            try
            {
                if (!Directory.Exists(dataFolderPath))
                {
                    Directory.CreateDirectory(dataFolderPath);
                }
                if (!File.Exists(dataName))
                {
                    SQLiteConnection.CreateFile(dataName);
                }
                //Console.WriteLine(connectionString);
                LocalDbConnection = new SQLiteConnection(connectionString);
                // 打开数据库连接
                LocalDbConnection.Open();

                if (TableExists("catalog_tb", LocalDbConnection))
                {
                    // 表存在

                    MessageBox.Show("表存在！");


                }
                else
                {
                    // 表不存在
                    MessageBox.Show("表不存在！");

                    string tableName = "catalog_tb";
                    string[] columnNames = { "id" ,"name" };
                    string[] columnTypes = { "INTEGER PRIMARY KEY AUTOINCREMENT  UNIQUE", "TEXT" };
                    CreateTable(tableName, columnNames, columnTypes, LocalDbConnection);

                }


                if (TableExists("block_tb", LocalDbConnection))
                {
                    // 表存在

                    MessageBox.Show("表存在！");
                        

                }
                else
                {
                    // 表不存在
                    MessageBox.Show("表不存在！");

                    string tableName = "block_tb";
                    string[] columnNames = { "id", "name", "catalog" ,"blockpath"};
                    string[] columnTypes = { "INTEGER PRIMARY KEY AUTOINCREMENT  UNIQUE", "TEXT", "TEXT", "TEXT" };
                    CreateTable(tableName, columnNames, columnTypes, LocalDbConnection);

                }
                MessageBox.Show("已连接数据库！");
                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show("连接数据库失败,请尝试管理员身份打开浩辰CAD！" );
               // MessageBox.Show("连接数据库失败！"+ex.ToString());
                //MessageBox.Show(connectionString);
                //MessageBox.Show(dataFolderPath);
                //MessageBox.Show(dataPath);
                return false;
            }

        }

        //判断是否存在表单
        public static bool TableExists(string tableName, SQLiteConnection connection)
        {
            string query = $"SELECT name FROM sqlite_master WHERE type='table' AND name='{tableName}'";

            using (SQLiteCommand command = new SQLiteCommand(query, connection))
            {
                object result = command.ExecuteScalar();
                return (result != null && result != DBNull.Value);
            }
        }

        //创建表单
        public static void CreateTable(string tableName, string[] columnNames, string[] columnTypes, SQLiteConnection connection)
        {
            // 构建创建表单的 SQL 语句
            string createTableSql = $"CREATE TABLE IF NOT EXISTS {tableName} (";

            for (int i = 0; i < columnNames.Length; i++)
            {
                createTableSql += $"{columnNames[i]} {columnTypes[i]}, ";
            }

            createTableSql = createTableSql.TrimEnd(',', ' ') + ")";

            // 执行创建表单命令
            using (SQLiteCommand command = new SQLiteCommand(createTableSql, connection))
            {
                command.ExecuteNonQuery();
            }
        }

        //新增表单
        public static void InsertData(string tableName, string[] columnNames, object[] values, SQLiteConnection connection)
        {
            // 构建插入数据的 SQL 语句
            string insertSql = $"INSERT INTO {tableName} ({string.Join(", ", columnNames)}) VALUES ({string.Join(", ", values.Select(v => "@" + v.ToString()))})";

            // 执行插入数据命令
            using (SQLiteCommand command = new SQLiteCommand(insertSql, connection))
            {
                for (int i = 0; i < columnNames.Length; i++)
                {
                    command.Parameters.AddWithValue("@" + columnNames[i], values[i]);
                }

                command.ExecuteNonQuery();
            }
        }
       
    }
}