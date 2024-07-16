using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json.Serialization;
using System.Text.Json;
using System.Threading.Tasks;

namespace Settings.UI.Library.CustomAction;
public class SendCustomAction
{
    private static readonly ConcurrentDictionary<string, JsonSerializerOptions> OptionsCache = new ConcurrentDictionary<string, JsonSerializerOptions>();

    private readonly string moduleName;

    public SendCustomAction(string moduleName)
    {
        this.moduleName = moduleName;
    }

    [JsonPropertyName("action")]
    public ModuleCustomAction Action
    {
        get; set;
    }

    public string ToJsonString()
    {
        var jsonSerializerOptions = OptionsCache.GetOrAdd(moduleName, CreateOptionsForModuleName);
        return JsonSerializer.Serialize(this, jsonSerializerOptions);
    }

    private JsonSerializerOptions CreateOptionsForModuleName(string moduleName)
    {
        return new JsonSerializerOptions
        {
            PropertyNamingPolicy = new CustomNamePolicy((propertyName) =>
            {
                // Using Ordinal as this is an internal property name
                return propertyName.Equals("ModuleAction", System.StringComparison.Ordinal) ? moduleName : propertyName;
            }),
        };
    }
}