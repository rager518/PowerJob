using System.Text.Json.Serialization;

namespace Settings.UI.Library.CustomAction;
public class CustomActionDataModel
{
    [JsonPropertyName("action_name")]
    public string Name
    {
        get; set;
    }

    [JsonPropertyName("value")]
    public string Value
    {
        get; set;
    }
}