using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using HostsUILib.Models;

namespace HostsUILib.Helpers;
public interface IHostsService
{
    string HostsFilePath
    {
        get;
    }

    event EventHandler FileChanged;

    Task<HostsData> ReadAsync();

    Task WriteAsync(string additionalLines, IEnumerable<Entry> entries);

    Task<bool> PingAsync(string address);

    void CleanupBackup();

    void OpenHostsFile();

    void RemoveReadOnly();
}