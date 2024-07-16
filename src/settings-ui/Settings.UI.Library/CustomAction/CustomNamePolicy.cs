using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace Settings.UI.Library.CustomAction;
public class CustomNamePolicy : JsonNamingPolicy
{
    private Func<string, string> convertDelegate;

    public CustomNamePolicy(Func<string, string> convertDelegate)
    {
        this.convertDelegate = convertDelegate;
    }

    public override string ConvertName(string name)
    {
        return convertDelegate(name);
    }
}