using System.Text.Json;

namespace PowerJob.Core.CustomAction;
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
