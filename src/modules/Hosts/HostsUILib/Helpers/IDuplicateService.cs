using System.Collections.Generic;
using HostsUILib.Models;

namespace HostsUILib.Helpers;
public interface IDuplicateService
{
    void Initialize(IList<Entry> entries);

    void CheckDuplicates(string address, string[] hosts);
}