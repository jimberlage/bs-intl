let () = {
    Jest.describe("Intl.DateTimeFormat", () => {
        Jest.describe("supportedLocalesOf", () => {
            Jest.test("it shows all the supported locales for the given list", () => {
                Jest.Expect.expect(Intl.DateTimeFormat.supportedLocalesOf([|"ban", "id-u-co-pinyin", "de-ID"|], ()))
                |> Jest.Expect.toEqual([|"id-u-co-pinyin", "de-ID"|]);
            })
        })

        Jest.describe("resolvedOptions", () => {
            Jest.test("it shows all the configured options for the given formatter", () => {
                let dt = Intl.DateTimeFormat.make(~locales=[|"de-DE"|], ~localeMatcher=BestFit, ~weekday=Long, ());
                Jest.Expect.expect(Intl.DateTimeFormat.resolvedOptions(dt).weekday)
                |> Jest.Expect.toEqual(Some(Intl.DateTimeFormat.Long));
            })
        })

        Jest.describe("format", () => {
            Jest.test("it builds a formatted date string", () => {
                let dt = Intl.DateTimeFormat.make(~locales=[|"fr"|], ~day=Numeric, ~month=Long, ());
                Jest.Expect.expect(Intl.DateTimeFormat.format(dt, Js.Date.makeWithYMD(~year=2019.0, ~month=6.0, ~date=22.0, ())))
                |> Jest.Expect.toEqual("22 juillet")
            })
        })

        Jest.describe("formatToParts", () => {
            Jest.test("it builds an array of parts to make a formatted date string", () => {
                let dt = Intl.DateTimeFormat.make(~locales=[|"zh-CN"|], ~era=Long, ~year=Numeric, ());
                Jest.Expect.expect(Intl.DateTimeFormat.formatToParts(dt, Js.Date.makeWithYMD(~year=2019.0, ~month=6.0, ~date=22.0, ())))
                |> Jest.Expect.toEqual([|
                    {
                        Intl.DateTimeFormat.type_: Era,
                        value: {js|公元|js},
                    },
                    {
                        type_: Year,
                        value: "2019",
                    },
                    {
                        type_: Literal,
                        value: {js|年|js},
                    },
                |])
            })
        })
    })
};