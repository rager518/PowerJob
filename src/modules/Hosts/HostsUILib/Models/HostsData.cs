using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HostsUILib.Models;
public class HostsData
{
    /// <summary>
    /// Gets the parsed entries
    /// </summary>
    public ReadOnlyCollection<Entry> Entries
    {
        get;
    }

    /// <summary>
    /// Gets the lines that couldn't be parsed
    /// </summary>
    public string AdditionalLines
    {
        get;
    }

    /// <summary>
    /// Gets a value indicating whether some entries been splitted
    /// </summary>
    public bool SplittedEntries
    {
        get;
    }

    public HostsData(List<Entry> entries, string additionalLines, bool splittedEntries)
    {
        Entries = entries.AsReadOnly();
        AdditionalLines = additionalLines;
        SplittedEntries = splittedEntries;
    }
}