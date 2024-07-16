﻿using System.Text.Json;
using System.Text.Json.Serialization;
using PowerJob.Core.Interfaces;

namespace PowerJob.Core.Converter;
public record BoolProperty : ICmdLineRepresentable
{
    public BoolProperty()
    {
        Value = false;
    }

    public BoolProperty(bool value)
    {
        Value = value;
    }

    [JsonPropertyName("value")]
    public bool Value
    {
        get; set;
    }

    public static bool TryParseFromCmd(string cmd, out object result)
    {
        result = null;

        if (!bool.TryParse(cmd, out bool value))
        {
            return false;
        }

        result = new BoolProperty { Value = value };
        return true;
    }

    public override string ToString()
    {
        return JsonSerializer.Serialize(this);
    }

    public bool TryToCmdRepresentable(out string result)
    {
        result = Value.ToString();
        return true;
    }
}