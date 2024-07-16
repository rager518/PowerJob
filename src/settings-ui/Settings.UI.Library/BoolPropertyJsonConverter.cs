using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json.Serialization;
using System.Text.Json;
using System.Threading.Tasks;

namespace Settings.UI.Library;
public class BoolPropertyJsonConverter : JsonConverter<bool>
{
    public override bool Read(ref Utf8JsonReader reader, Type typeToConvert, JsonSerializerOptions options)
    {
        var boolProperty = JsonSerializer.Deserialize<BoolProperty>(ref reader, options);
        return boolProperty.Value;
    }

    public override void Write(Utf8JsonWriter writer, bool value, JsonSerializerOptions options)
    {
        var boolProperty = new BoolProperty(value);
        JsonSerializer.Serialize(writer, boolProperty, options);
    }
}